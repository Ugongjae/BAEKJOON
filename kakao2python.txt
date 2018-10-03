def swa1(x):
    return x[1]
def swa2(x):
    return x[0]

def solution(N, stages):

    st=[[0 for cols in range(2)]for rows in range(N+2)]
    for i in range(0,N+2):
        st[i][0]=i

    for i in stages:

            st[i][1]=st[i][1]+1

    tmp=st[N+1][1];
    for i in range(N,0,-1):
        tmp+=st[i][1]
        st[i][1]=st[i][1]/float(tmp)*(-1)

    st=sorted(st, key=lambda x: (swa1(x), swa2(x)))
    answer = []
    for i in st:
        if i[0]==0 or i[0]==N+1:
            continue
        else:
            answer.append(i[0])


    return answer

