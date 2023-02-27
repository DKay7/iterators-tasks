
namespace it {

void print_left_than (const std::vector<int>& data, const int num);
std::vector<std::string> split_str (std::string str, const char delimeter = ' ');

template <typename T>
std::vector<T> set_elements_greater_than(const std::set<T>& data, const T& elem) {
    std::vector<T> result;
    
    for (auto it = data.upper_bound(elem); it != data.end(); ++it) {
        result.push_back(*it);
    }

    std::reverse(result.begin(), result.end());
    return result;
}

} // namespace it