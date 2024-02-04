# 프로그래머스 광물캐기
# https://school.programmers.co.kr/learn/courses/30/lessons/172927?language=python3

def solution(picks, minerals):
    answer = []
    tired=[[1,1,1],[5,1,1],[25,5,1]]
    tools={"diamond":0, "iron":1, "stone":2}
    
    def dfs(picks,minerals, tired_rate):
        if sum(picks)==0 or minerals==[]: 
            answer.append(tired_rate) 
            return
        m=minerals[:5] 
        
        for i in range(3):
            if picks[i] > 0:
                picks[i] -= 1
                tired_val=0
                for j in m:
                    tired_val +=tired[i][tools[j]]
                dfs(picks, minerals[5:], tired_rate+tired_val)
                picks[i] += 1
    
    dfs(picks, minerals, 0)
    answer.sort()
    return answer[0]
