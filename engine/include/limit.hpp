// engine/include/limit.hpp
#pragma once

#include "order.hpp"
#include "types.hpp"

namespace lob {

struct Limit {
    u64 limit_price;
    u64 size;
    u64 total_volume;
    Limit *parent;
    Limit *left_child;
    Limit *right_child;
    Order *head_order;
    Order *tail_order;
}

} // namespace lob
