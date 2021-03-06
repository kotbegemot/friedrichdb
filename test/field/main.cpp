#include "friedrichdb/core/basic_field.hpp"
#include <boost/interprocess/smart_ptr/unique_ptr.hpp>
#include <boost/move/unique_ptr.hpp>
#include <iostream>

using namespace friedrichdb::core;

template<class T, class D = boost::movelib::default_delete<T> >
using unique_ptr_t =  boost::interprocess::unique_ptr<T, D>;

using field_base = basic_field<std::allocator, unique_ptr_t>;

int main() {

    field_base boolean(true);
    field_base string_("1111");
    field_base number(int(3));
    field_base number_(int(2));

    field_base map_;
    map_.emplace("qq",1);
    auto&d = map_.at("qq");

    field_base array_;
    array_.emplace_back(1);
    array_.emplace_back(2);
    auto&d1 = array_.at(0);

    std::cerr << (number < number_) << std::endl;
    return 0;
}