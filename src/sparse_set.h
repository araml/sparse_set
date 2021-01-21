#ifndef __SPARSE_SET_H__
#define __SPARSE_SET_H__

#include <memory>
#include <vector>

template <typename T,
          typename A = std::allocator<T>,
          typename A_INDX = std::allocator<size_t>>
class sparse_set {
public:
    using value_type = T;
    using allocator_type = A;
    using size_type = typename A::size_type;
    using difference_type = typename A::difference_type;

    using iterator = typename std::vector<T, A>::iterator;
    using const_iterator = typename std::vector<T, A>::const_iterator;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    using pointer = typename A::pointer;
    using const_pointer = typename A::const_pointer;
    using reference = typename A::reference;
    using const_reference = typename A::const_reference;

    sparse_set() {}

    sparse_set(sparse_set &&s) = default;
    sparse_set(const sparse_set &s) = default;

    auto operator=(sparse_set &&s) -> sparse_set& = default;
    auto operator=(const sparse_set &s) -> sparse_set& = default;

    auto insert(size_t idx, const T &v) -> void {
        if (_indices.size() <= idx) { // gota resize
            _indices.resize(idx + 1, -1);
        }

        // handle resizes as well
        if (_indices[idx] == -1) {
            _indices[idx] = _last_available++;
        }

        _values.push_back(v);
        _indices[idx] = _values.size() - 1;
    }

    auto erase(size_t idx) -> void {
        std::swap(_values[_indices[idx]], _values.back());
        std::swap(_indices[idx], _indices.back());
        _indices.back() = -1;
        _values.pop_back();
        _last_available--;
    }

    auto operator[](size_t idx) -> T& {
        if (_indices[idx] != -1) {
            return _values[_indices[idx]];
        } // throw?
    }

    auto begin() -> iterator {
        return std::begin(_values);
    }

    auto end() -> iterator {
        return std::end(_values);
    }

    auto cbegin() const -> const_iterator {
        return std::cbegin(_values);
    }

    auto cend() const -> const_iterator {
        return std::cend(_values);
    }

    /* Note, no reverse iterator since we actually don't care about the order
     * of the elements relative to the data structure.
     */

    auto size() -> size_t {
        return _values.size();
    }

private:
    size_t _size{0};
    size_t _last_available{0}; // indicates last avail pos in _values
    std::vector<ssize_t, A_INDX> _indices;
    std::vector<T, A> _values;
};


#endif // __SPARSE_SET_H__
