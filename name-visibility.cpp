#include <iostream>

using namespace std;

// int foo;        // global variable

// int some_function ()
// {
//   int bar;      // local variable
//   bar = 0;
// }

// int other_function ()
// {
//   foo1 = 1;  // ok: foo is a global variable
// }

namespace foo
{
  int value() { return 5; }
}
namespace foo { int c; }

namespace bar
{
  const double pi = 3.1416;
  double value() { return 2*pi; }
}

namespace first
{
  int x = 5;
//   int y = 10;
}

namespace second
{
  double x = 3.1416;
  double y = 2.7183;
}

int x;

int main(){
    /** NAMESPACES */
    // cout << foo::c << " C" << '\n';
    // cout << foo::value() << '\n';
    // cout << bar::value() << '\n';
    // cout << bar::pi << '\n';

    /** USING */
    // #EXAMPLE # 1
    // using first::x;
    // using second::y;
    // cout << x << '\n';
    // cout << y << '\n';
    // cout << first::y << '\n';
    // cout << second::x << '\n';

    // #EXAMPLE #2
    // using namespace first;
    // cout << x << '\n';
    // cout << y << '\n';
    // cout << second::x << '\n';
    // cout << second::y << '\n';

    // #EXAMPLE #3
    // {
    //     using namespace first;
    //     cout << x << '\n';
    // }
    // {
    //     using namespace second;
    //     cout << x << '\n';
    // }

    /** NAMESPACE ALIASING */
    // namespace alias = first;  // Creating an alias for the 'first' namespace

    /** STORAGE CLASSES */
    // int y;
    // cout << x << '\n';
    // cout << y << '\n';
    return 0;
}