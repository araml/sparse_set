#ifndef __SPARSE_SET_H__
#define __SPARSE_SET_H__

#include <memory>
#include <vector>

template <typename T, typename Allocator = std::allocator<T>>
class sparse_set {
public:
    sparse_set() : _indices(10, -1) {
        _values.resize(10);
    }

    auto insert(size_t idx, const T &v) -> void {
        if (_indices.size() < idx) { // gota resize
            _indices.resize(idx + 1, -1);
            _values.resize(idx + 1);
            _indices[idx] = _last_available++;
        }

        // handle resizes as well
        if (_indices[idx] == -1) {
            _indices[idx] = _last_available++;
        }
        _values[_indices[idx]] = v;
    }

    auto operator[](size_t idx) -> T& {
        return _values[_indices[idx]];
    }

    auto begin() -> decltype(std::begin(std::vector<ssize_t, std::allocator<ssize_t>>{})) {
        return std::begin(_indices);
    }

    auto end() -> decltype(std::end(std::vector<ssize_t, std::allocator<ssize_t>>{})) {
        return std::end(_indices);
    }


private:
    size_t _size{0};
    size_t _last_available{0}; // indicates last avail pos in _values
    std::vector<ssize_t, std::allocator<ssize_t>> _indices;
    std::vector<T, Allocator> _values;
};


#endif // __SPARSE_SET_H__
