// engine/include/book.hpp
#pragma once

#include "limit.hpp"

namespace lob {

struct Limit;

struct Book {
    Limit *buy_tree;
    Limit *sell_tree;
    Limit *lowest_sell;
    Limit *highest_buy;
}

} // namespace lob
