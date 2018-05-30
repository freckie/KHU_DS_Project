#ifndef AVL_MAP_H
#define AVL_MAP_H

#include <cassert>
//#include "type_choose.h"

template<typename KEY, typename VALUE>
class avl_map {
private:
	//////////////////////////////////////////////////////////////////////////
	// Vertex type

	struct vertex {
		vertex *parent;
		vertex *left, *right;
		int height;

		KEY key;
		VALUE value;

		vertex(const KEY &init_key, const VALUE &init_value) :
			key(init_key), value(init_value) {}
	};

public:
	//////////////////////////////////////////////////////////////////////////
	// Exceptions

	class exception {};
	class key_does_not_exist : public exception {};
	class key_already_exists : public exception {};

	//////////////////////////////////////////////////////////////////////////
	// Iterator

	template<bool is_const_iterator = true>
	class const_noconst_iterator {
	private:
		typedef typename type_choose<is_const_iterator, const avl_map *, avl_map *>::type DataStructurePointerType;
		typedef typename type_choose<is_const_iterator, const vertex *, vertex *>::type VertexPointerType;
		typedef typename type_choose<is_const_iterator, const VALUE &, VALUE &>::type ValueReferenceType;

	public:
		const_noconst_iterator(VertexPointerType ptr) : m_vertex_ptr(ptr) {
		}

		const_noconst_iterator(const const_noconst_iterator<false> &other) : m_vertex_ptr(other.m_vertex_ptr) {
		}

		const_noconst_iterator &operator=(const const_noconst_iterator<false> &other) {
			m_vertex_ptr = other.m_vertex_ptr;
			return *this;
		}

		bool operator==(const const_noconst_iterator &other) const {
			return m_vertex_ptr == other.m_vertex_ptr;
		}

		bool operator!=(const const_noconst_iterator &other) const {
			return !(*this == other);
		}

		ValueReferenceType operator*() {
			return m_vertex_ptr->value;
		}

		const_noconst_iterator &operator++() {
			assert(m_vertex_ptr);
			m_vertex_ptr = get_next_vertex(m_vertex_ptr);
			return *this;
		}

		const_noconst_iterator operator++(int) {
			// Use operator++()
			const const_noconst_iterator old(*this);
			++(*this);
			return old;
		}

		// Make const_noconst_iterator<true> a friend class of const_noconst_iterator<false> so
		// the copy constructor can access the private member variables.
		friend class const_noconst_iterator<true>;

		const KEY &key() {
			return m_vertex_ptr->key;
		}

		ValueReferenceType value() {
			return m_vertex_ptr->value;
		}

	private:
		VertexPointerType m_vertex_ptr; // store a reference to the map
	};

	typedef const_noconst_iterator<false> iterator;
	typedef const_noconst_iterator<true> const_iterator;

	//////////////////////////////////////////////////////////////////////////
	// Functions

	avl_map() {}
	avl_map(const avl_map &other) {
		for (auto it = other.cbegin(); it != other.cend(); ++it) {
			insert_last(it.key(), it.value());
		}
	}
	~avl_map() {
		clear();
	}
	avl_map &operator=(const avl_map &other) {
		clear();
		for (auto it = other.cbegin(); it != other.cend(); ++it) {
			insert_last(it.key(), it.value());
		}
		return *this;
	}

	bool operator==(const avl_map &other) const {
		auto other_it = other.cbegin();
		if (other_it == other.cend()) {
			return cbegin() == cend();
		}

		for (auto it = cbegin(); it != cend(); ++it) {
			if (other_it == other.cend()) {
				return false;
			}

			if (it.key() != other_it.key()) {
				return false;
			}

			if (it.value() != other_it.value()) {
				return false;
			}

			++other_it;
		}

		return other_it == other.cend();
	}
	bool operator!=(const avl_map &other) const {
		return !(*this == other);
	}

	iterator begin() {
		return iterator(m_first);
	}
	iterator end() {
		return iterator(nullptr);
	}
	const_iterator begin() const {
		return const_iterator(m_first);
	}
	const_iterator end() const {
		return const_iterator(nullptr);
	}
	const_iterator cbegin() const {
		return begin();
	}
	const_iterator cend() const {
		return end();
	}

	bool empty() const {
		return cbegin() == cend();
	}
	size_t size() const {
		return m_size;
	}

	// Throws if key doesn't exist.
	VALUE &at(const KEY &key) {
		iterator it = find(key);
		if (it == end()) {
			throw key_does_not_exist();
		}

		return *it;
	}
	const VALUE &at(const KEY &key) const {
		const_iterator it = find(key);
		if (it == cend()) {
			throw key_does_not_exist();
		}

		return *it;
	}

	// Exception is thrown if key already exists.
	iterator insert(const KEY &key, const VALUE &value) {
		bool exists;
		iterator it = insert(key, value, exists);
		if (exists) {
			throw key_already_exists();
		}

		return it;
	}
	iterator insert(const KEY &key, const VALUE &value, bool &exists) {
		vertex *v = try_to_find(m_root, key);
		if (v && key == v->key) {
			exists = true;
			return iterator(v);
		}

		exists = false;
		return insert_at(v, key, value);
	}
	// The following functions optimize the insertion time if the inserted
	// key is lower/greater than all existing keys.
	// Exception is thrown if key already exists.
	iterator insert_first(const KEY &key, const VALUE &value) {
		if (m_first && !(key < m_first->key)) {
			return insert(key, value); // unoptimized insert
		}

		return insert_at(m_first, key, value);
	}
	iterator insert_last(const KEY &key, const VALUE &value) {
		if (m_last && !(key > m_last->key)) {
			return insert(key, value); // unoptimized insert
		}

		return insert_at(m_last, key, value);
	}

	bool erase(const KEY &key) {
		vertex *v = try_to_find(m_root, key);
		if (!v || key != v->key) {
			return false;
		}

		erase_vertex(v);
		return true;
	}
	void clear() {
		delete_all_recursive(m_root);
		m_root = m_first = m_last = nullptr;
		m_size = 0;
	}

	iterator find(const KEY &key) {
		vertex *v = try_to_find(m_root, key);
		if (!v || key != v->key) {
			return end();
		}

		return iterator(v);
	}
	const_iterator find(const KEY &key) const {
		vertex *v = try_to_find(m_root, key);
		if (!v || key != v->key) {
			return cend();
		}

		return const_iterator(v);
	}

private:
	vertex * m_root = nullptr;
	vertex *m_first = nullptr, *m_last = nullptr;
	size_t m_size = 0;

	//////////////////////////////////////////////////////////////////////////
	// Helper functions

	// Returns the vertex with the next larger key.
	static vertex *get_next_vertex(vertex *v) {
		if (v) {
			if (v->right) {
				v = v->right;
				while (v->left) {
					v = v->left;
				}
			}
			else if (v->parent) {
				vertex *prev_ptr = v;
				v = v->parent;
				while (v && v->right == prev_ptr) {
					prev_ptr = v;
					v = v->parent;
				}
			}
			else {
				v = nullptr; // we reached the end
			}
		}

		return v;
	}

	static const vertex *get_next_vertex(const vertex *v) {
		// http://stackoverflow.com/a/123995
		return const_cast<const vertex *>(get_next_vertex(const_cast<vertex *>(v)));
	}

	void swap_vertex_locations(vertex *v1, vertex *v2) {
		// swap child/parent pointers
		vertex *parent1 = v1->parent;
		vertex *parent2 = v2->parent;

		if (parent1) {
			if (parent1->left == v1) {
				parent1->left = v2;
			}
			else {
				assert(parent1->right == v1);
				parent1->right = v2;
			}
		}
		else {
			assert(m_root == v1);
			m_root = v2;
		}
		v1->parent = parent2;

		if (parent2) {
			if (parent2->left == v2) {
				parent2->left = v1;
			}
			else {
				assert(parent2->right == v2);
				parent2->right = v1;
			}
		}
		else {
			assert(m_root == v2);
			m_root = v1;
		}
		v2->parent = parent1;

		// swap left/right pointers and height

		vertex *left1 = v1->left;
		vertex *right1 = v1->right;
		int height1 = v1->height;
		vertex *left2 = v2->left;
		vertex *right2 = v2->right;
		int height2 = v2->height;

		if (left1) {
			left1->parent = v2;
		}
		if (right1) {
			right1->parent = v2;
		}
		v1->left = left2;
		v1->right = right2;
		v1->height = height2;

		if (left2) {
			left2->parent = v1;
		}
		if (right2) {
			right2->parent = v1;
		}
		v2->left = left1;
		v2->right = right1;
		v2->height = height1;
	}

	// Tries to find the value with the given key, starting from the given
	// vertex down the tree. If not found, returns the latest vertex in the
	// search path.
	static vertex *try_to_find(vertex *v, const KEY &key) {
		if (!v) {
			return nullptr;
		}

		while (key != v->key) {
			vertex *v_next;

			if (key < v->key) {
				v_next = v->left;
			}
			else {
				v_next = v->right;
			}

			if (!v_next) {
				return v; // not found, return latest vertex
			}

			v = v_next;
		}

		return v;
	}

	iterator insert_at(vertex *v, const KEY &key, const VALUE &value) {
		vertex *v_new = new vertex(key, value);
		v_new->parent = v;
		v_new->left = v_new->right = nullptr;
		v_new->height = 0;

		if (v) {
			if (key < v->key) {
				assert(!v->left);
				v->left = v_new;
				if (m_first == v) {
					m_first = v_new;
				}
			}
			else {
				assert(key > v->key);
				assert(!v->right);
				v->right = v_new;
				if (m_last == v) {
					m_last = v_new;
				}
			}
		}
		else {
			assert(!m_root && !m_first && !m_last && m_size == 0);
			m_root = m_first = m_last = v_new;
		}

		m_size++;

		rebalance_from_vertex(v);

		return iterator(v_new);
	}

	void erase_vertex(vertex *v) {
		if (v->left && v->right) {
			vertex *swap_with = get_next_vertex(v);
			assert(swap_with);

			swap_vertex_locations(v, swap_with);
			assert(!v->left || !v->right);
		}

		vertex *parent = v->parent;
		vertex *next = nullptr;

		if (v->left) {
			next = v->left;
		}
		else if (v->right) {
			next = v->right;
		}

		if (next) {
			next->parent = parent;
		}

		if (v == m_root) {
			assert(!parent);
			m_root = next;
		}
		else if (parent->left == v) {
			parent->left = next;
		}
		else {
			assert(parent->right == v);
			parent->right = next;
		}

		if (m_first == v) {
			if (next) {
				m_first = next;
				while (m_first->left) {
					m_first = m_first->left;
				}
			}
			else {
				m_first = parent;
			}
		}

		if (m_last == v) {
			if (next) {
				m_last = next;
				while (m_last->right) {
					m_last = m_last->right;
				}
			}
			else {
				m_last = parent;
			}
		}

		delete v;
		m_size--;

		rebalance_from_vertex(parent);
	}

	void rebalance_from_vertex(vertex *v) {
		if (!v) {
			return;
		}

		int balance_factor = calculate_balance_factor(v);
		int prev_height = v->height;

		if (balance_factor == 2) {
			int left_balance_factor = calculate_balance_factor(v->left);
			if (left_balance_factor >= 0) {
				v = rotate_left_left(v);
			}
			else {
				v = rotate_left_right(v);
			}
		}
		else if (balance_factor == -2) {
			int right_balance_factor = calculate_balance_factor(v->right);
			if (right_balance_factor <= 0) {
				v = rotate_right_right(v);
			}
			else {
				v = rotate_right_left(v);
			}
		}
		else {
			assert(balance_factor >= -1 && balance_factor <= 1);
			invalidate_height(v);
		}

		if (v->height != prev_height) {
			rebalance_from_vertex(v->parent);
		}
	}

	static int calculate_balance_factor(const vertex *v) {
		int balance_factor = 0;
		if (v->left) {
			balance_factor += 1 + v->left->height;
		}
		if (v->right) {
			balance_factor -= 1 + v->right->height;
		}
		return balance_factor;
	}

	vertex *rotate_right(vertex *v) {
		vertex *parent = v->parent;
		vertex *left = v->left;
		vertex *left_right = left->right;

		if (!parent) {
			assert(v == m_root);
			m_root = left;
		}
		else if (parent->left == v) {
			parent->left = left;
		}
		else {
			assert(parent->right == v);
			parent->right = left;
		}
		left->parent = parent;
		left->right = v;

		v->parent = left;
		v->left = left_right;
		if (left_right) {
			left_right->parent = v;
		}

		invalidate_height(v);
		invalidate_height(left);

		return left;
	}

	vertex *rotate_left(vertex *v) {
		vertex *parent = v->parent;
		vertex *right = v->right;
		vertex *right_left = right->left;

		if (!parent) {
			assert(v == m_root);
			m_root = right;
		}
		else if (parent->right == v) {
			parent->right = right;
		}
		else {
			assert(parent->left == v);
			parent->left = right;
		}
		right->parent = parent;
		right->left = v;

		v->parent = right;
		v->right = right_left;
		if (right_left) {
			right_left->parent = v;
		}

		invalidate_height(v);
		invalidate_height(right);

		return right;
	}

	vertex *rotate_left_left(vertex *v) {
		return rotate_right(v);
	}

	vertex *rotate_right_right(vertex *v) {
		return rotate_left(v);
	}

	vertex *rotate_left_right(vertex *v) {
		rotate_left(v->left);
		return rotate_right(v);
	}

	vertex *rotate_right_left(vertex *v) {
		rotate_right(v->right);
		return rotate_left(v);
	}

	static void invalidate_height(vertex *v) {
		int left_height = v->left ? v->left->height : -1;
		int right_height = v->right ? v->right->height : -1;

		v->height = 1 + ((left_height > right_height) ? left_height : right_height);
	}

	static void delete_all_recursive(vertex *v) {
		if (v) {
			delete_all_recursive(v->right);
			delete_all_recursive(v->left);
			delete v;
		}
	}
};

#endif // AVL_MAP_H