#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <numeric>
template <typename weight_type,
typename value_type,
typename fractional_type>
struct Object
{
using Wtype = weight_type;
using Vtype = value_type;
using Ftype = fractional_type;
Wtype weight;
Vtype value;
Ftype value_per_unit_weight;
inline bool operator< (const Object<Wtype,Vtype,Ftype>& obj) const
{

return this->value_per_unit_weight < obj.value_per_unit_weight;
}
inline bool operator== (const Object<Wtype, Vtype, Ftype>& obj) const
{
return this->value_per_unit_weight == obj.value_per_unit_weight;
}
template <typename Wtype,
typename Vtype,
typename Ftype>
friend std::ostream& operator<<(std::ostream& os,
const Object<Wtype,Vtype,Ftype>& obj);
};

template <typename Wtype,
typename Vtype,
typename Ftype>
std::ostream& operator<<(std::ostream& os, const
Object<Wtype,Vtype,Ftype>& obj)
{
os << "Value: "<<obj.value
<< "\t Weight: " << obj.weight
<<"\t Value/Unit Weight: " << obj.value_per_unit_weight;
return os;
}
