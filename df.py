from fractions import Fraction

def solution(m):
    # the matrix can be treated as a absorbing markov chain
    # ref: https://en.wikipedia.org/wiki/Absorbing_Markov_chain
    
    # we wish to find the limiting matrix of the given input
    # ref: https://www.youtube.com/watch?v=BsOkOaB8SFk
    
    # standardize the matrix
    def processMatrix(m):
        row_sum = [sum(m[i]) for i in range(len(m))]        # sum of each row of given matrix
        bool_terminal = [x == 0 for x in row_sum]           # bool_terminal[i] represents if ith row is terminal or not
        terminal_rows = set([i for i, x in enumerate(bool_terminal) if x])      # indices of terminal rows in m
        
        # add fractions of probability => row_element/row_sum
        tmp_m = []
        for i in range(len(m)):
            tmp_m.append(list(map(lambda x : Fraction(0, 1) if(row_sum[i] == 0) else Fraction(x, row_sum[i]), m[i])))

        # seperate the terminal and non-terminal states
        non_term_mat = []
        zero_mat = []
        for i in range(len(tmp_m)):
            if i in terminal_rows:
                zero_mat.append(tmp_m[i])
            else:
                non_term_mat.append(tmp_m[i])

        # zero_mat.extend(non_term_mat)
        non_term_mat.extend(zero_mat)

        # final processing          (shifting columns to match with terminal & non-terminal rows)
        processedMatrix = []
        for i in range(len(non_term_mat)):
            processedMatrix.append([])
            tmp = []
            for j in range(len(non_term_mat)):
                if j in terminal_rows:
                    tmp.append(non_term_mat[i][j])
                else:
                    processedMatrix[i].append(non_term_mat[i][j])
            processedMatrix[i].extend(tmp)

        # the zero_mat length helps in easier split and early stopping
        return processedMatrix, len(zero_mat)

    def splitIntoQR(m, zero_len):
        """
        --------------
        | q |   r    |
        --------------
        |   |        |
        | 0 |   I    |
        |   |        |
        --------------
        """
        q_len = len(m) - zero_len   # size of side of q matrix
        q_mat = []
        r_mat = []

        for i in range(q_len):
            q_mat.append([int(i==j) - m[i][j] for j in range(q_len)])           # performing the (I-Q) step in-place
            r_mat.append(m[i][q_len:])

        return q_mat, r_mat

    # create a copy of the matrix
    def copyMat(m):
        copy_mat = []
        for i in range(len(m)):
            copy_mat.append([])
            for j in range(len(m[i])):
                # copy_mat[i].append(Fraction(m[i][j].numerator, m[i][j].denominator))
                copy_mat[i].append(m[i][j])
        return copy_mat

    # ref: https://elonen.iki.fi/code/misc-notes/python-gaussj/
    def gaussJordanElmination(m, i_row):
        mat = copyMat(m)

        for i in range(len(mat)):
            idx = -1
            for j in range(i, len(mat)):
                if mat[j][i].numerator != 0:
                    idx = j
                    break
            if idx == -1:
                raise ValueError('error: Gauss elimination failed!')
            mat[i], mat[idx] = mat[idx], mat[j]
            i_row[i], i_row[idx] = i_row[idx], i_row[i]
            for j in range(i+1, len(mat)):
                if mat[j][i].numerator == 0:
                    continue
                ratio = -mat[j][i]/mat[i][i]
                for k in range(i, len(mat)):
                    mat[j][k] += ratio * mat[i][k]
                i_row[j] += ratio * i_row[i]
        
        result = [0 for i in range(len(mat))]
        for i in range(len(mat)):
            idx = len(mat) - 1 - i
            end = len(mat) - 1
            while end > idx:
                i_row[idx] -= mat[idx][end] * result[end]
                end -= 1
            result[idx] = i_row[idx]/mat[idx][idx]

        return result

    # create transpose of matrix
    def transposeMat(m):
        result = []
        for i in range(len(m)):
            for j in range(len(m)):
                if i == 0:
                    result.append([])
                result[j].append(m[i][j])
        return result

    # find inverse of the matrix
    def inverseMat(m):
        trans_m = transposeMat(m)
        inverse_m = []
        for i in range(len(trans_m)):
            identity_mat_row = [Fraction(int(i==j), 1) for j in range(len(trans_m))]
            inverse_m.append(gaussJordanElmination(trans_m, identity_mat_row))

        return inverse_m

    # multiply matrix m1 with matrix m2
    def multiplyMat(m1, m2):
        result = []
        for i in range(len(m1)):
            result.append([])
            for j in range(len(m2[0])):
                result[i].append(Fraction(0, 1))
                for k in range(len(m1[0])):
                    result[i][j] += m1[i][k] * m2[k][j]

        return result

    # greatest common divisor of x and y
    def gcd(x, y):
        def _gcd(x, y):
            if y == 0:
                return x
            return _gcd(y, x%y)
        # return _gcd(x, y)
        return _gcd(abs(x), abs(y))

    # calculate lowest common multiple of x & y
    def lcm(x, y):
        # return int((x*y)/gcd(abss(x),abs(y)))
        return int((x*y)/gcd(x,y))

    ## solution begins hers
    m, zero_len = processMatrix(m)
    
    # if all rows are terminal
    if zero_len == len(m):
        return [1,1]
    
    # get (i-q) & r matrix
    q_mat, r_mat = splitIntoQR(m, zero_len)
    # get inv(i-q)
    inv_q_mat = inverseMat(q_mat)
    # get the limiting matrix
    limiting_mat = multiplyMat(inv_q_mat, r_mat)

    sol = limiting_mat[0]

    # solve each fraction for common denominator as per the readme.txt
    common_denominator = 1
    for item in sol:
        common_denominator = lcm(common_denominator, item.denominator)
    
    result = list(map(lambda x : int((x.numerator*common_denominator)/x.denominator), sol))
    result.append(common_denominator)

    return result