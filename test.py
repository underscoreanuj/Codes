def calc(expression):
    try:

        print(expression)
        prec = {
            '+': 1,
            '-': 1,
            '*': 2,
            '/': 2
        }

        def filter(s):
            while "--" in s:
                s = s.replace('--', '+')
            while "++" in s:
                s = s.replace('++', '+')
            while "+-" in s:
                s = s.replace('+-', '-')
            while "/+" in s:
                s = s.replace('/+', '/')
            while "*+" in s:
                s = s.replace('*+', '*')

            return s

        expression = ''.join(expression.split(' '))
        expression = filter(expression)
        print(expression)
        expression = expression.replace('-', ' - ').replace('+', ' + ').replace(
            '*', ' * ').replace('/', ' / ').replace('(', ' ( ').replace(')', ' ) ')
        expression = expression.split(' ')
        expression = [e for e in expression if len(e) > 0]
        print(expression)

        def evaluate(left, right, op):
            if op == '+':
                return left + right
            elif op == '-':
                return left - right
            elif op == '*':
                return left * right
            elif op == '/':
                return left / right

            return 0

        expr = []
        count = 0
        for i, e in enumerate(expression):
            if e == '-' and (i == 0 or expression[i-1] in prec or expression[i-1] == '('):
                if expression[i+1] != '(':
                    expr.append('(')
                    count += 1
                expr.append(-1)
                expr.append('*')

            elif e in prec:
                expr.append(e)
            elif e.isdigit():
                expr.append(int(e))
                if count > 0:
                    expr.append(')')
                    count -= 1
            else:
                expr.append(e)

        while count > 0:
            expr.append(')')
            count -= 1

        print('*****************************')
        print(expr)

        stack = []
        exp = []
        for e in expr:
            if e == '(':
                stack.append('(')
            elif e == ')':
                while stack[-1] != '(':
                    exp.append(stack[-1])
                    stack.pop()
                stack.pop()
            elif e in prec:
                if len(stack) == 0 or stack[-1] == '(':
                    stack.append(e)
                else:
                    if len(stack) and stack[-1] != '(':
                        while len(stack) and stack[-1] != '(' and prec[e] <= prec[stack[-1]]:
                            exp.append(stack[-1])
                            stack.pop()
                    stack.append(e)
            else:
                exp.append(e)

        while len(stack):
            exp.append(stack[-1])
            stack.pop()

        print('***********************************')
        for e in exp:
            print(e, end=', ')

        stack = []
        for e in exp:
            if e in prec:
                right = stack[-1]
                stack.pop()
                left = stack[-1]
                stack.pop()
                result = evaluate(left, right, e)
                stack.append(result)
            else:
                stack.append(e)

        return stack[-1]
    except:
        return -1


print("\n\n\n-*************************\n",
      calc("(-3 * -(((-(-67 - 27)))) - 70)"))
