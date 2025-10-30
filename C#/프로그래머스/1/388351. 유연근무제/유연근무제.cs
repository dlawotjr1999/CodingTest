using System;
using System.Collections.Generic;

public class Solution {
    public int solution(int[] schedules, int[,] timelogs, int startday) {
        int answer = 0;
        
        int people = timelogs.GetLength(0);
        int day = timelogs.GetLength(1);
        
        for(int i = 0; i < people; ++i) {
            bool isOK = true;
            int curday = startday;
            
            int scheduletime = (schedules[i] / 100) * 60 + (schedules[i] % 100); 
            
            for(int j = 0; j < day; ++j) {
                int curtime = (timelogs[i, j] / 100) * 60 + (timelogs[i, j] % 100); 
                int diff = curtime - scheduletime;
                
                if(diff > 10 && curday != 6 && curday != 7) {
                    isOK = false;
                    break;
                }

                curday++;
                if(curday > 7) curday -= 7;
                
            }
            if(isOK)
                answer++;
        }
        
        return answer;
    }
}