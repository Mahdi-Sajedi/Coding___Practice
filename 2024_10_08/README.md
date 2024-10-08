[cppreference: std::inner_product](https://en.cppreference.com/w/cpp/algorithm/inner_product)

Notes
The parallelizable version of this algorithm, std::transform_reduce, requires op1 and op2 to be commutative and associative, but std::inner_product makes no such requirement, and always performs the operations in the order given.
