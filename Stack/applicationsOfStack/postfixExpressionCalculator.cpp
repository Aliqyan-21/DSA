#include "../stackAsArrays/stackType.h"

int evaluateExpr(char exp, float op1, float op2) {
  switch (exp) {
  case '+':
    return op1 + op2;
    break;
  case '-':
    return op1 - op2;
    break;
  case '*':
    return op1 * op2;
    break;
  case '/':
    return op1 / op2;
    break;
  default:
    std::cout << "Error in expression" << std::endl;
    exit(1);
    break;
  }
}

int main(void) {
  StackType<double> st(100);
  std::string expression;
  getline(std::cin, expression);
  float op1, op2, tmp;

  for (auto &a : expression) {
    if (a == '+' || a == '-' || a == '*' || a == '/' || a == '-') {
      op1 = st.top();
      st.pop();
      op2 = st.top();
      st.pop();
      tmp = evaluateExpr(a, op1, op2);
      st.push(tmp);
    } else {
      st.push(a);
    }
  }

  std::cout << st.top() << std::endl;

  return 0;
}
