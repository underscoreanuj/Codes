def solution(total_lambs):
    # if being stingy   : follow a fibonacci sequence
    # if being generous : follow a geometric progression of power of 2
    # generous_count = int(round(math.log(total_lambs+1, 2)))      # min possible
    generous_count = 1      # min possible
    stingy_count = 0        # max possible
    
    # calculate generous count
    while True:
        total = 2**generous_count-1
        if total <= total_lambs:
            generous_count += 1
        else:
            generous_count -= 1
            break
            
    # calculate stingy count
    f1 = 1
    f2 = 1
    total = 0
    while total + f1 <= total_lambs:
        total += f1
        f1, f2 = f2, f1 + f2
        stingy_count += 1
        
    return stingy_count - generous_count
        


print(solution(143))