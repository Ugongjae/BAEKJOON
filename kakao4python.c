def solution(food_times, k):
    j=0
    for i in range(0, k):
        if food_times[j]!=0:
            food_times[j]=food_times[j]-1
        else:
            while(food_times[j]==0):
                j=(j+1)%len(food_times)
            food_times[j] = food_times[j] - 1
        j=(j+1)%len(food_times)

    answer = 0
    if food_times[j] != 0:
        answer=j+1
    else:
        while (food_times[j] == 0):
            j = (j + 1) % len(food_times)
        answer=j+1
    return answer