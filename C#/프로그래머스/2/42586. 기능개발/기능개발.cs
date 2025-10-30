using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        List<int> answer = new List<int>();
        Queue<int> queue = new Queue<int>();

        for (int i = 0; i < progresses.Length; i++) {
            int remain = 100 - progresses[i];
            int days = (int)Math.Ceiling((double)remain / speeds[i]);
            queue.Enqueue(days);
        }

        while (queue.Count > 0) {
            int cur = queue.Dequeue(); 
            int cnt = 1;

            while (queue.Count > 0 && queue.Peek() <= cur) {
                queue.Dequeue();
                cnt++;
            }

            answer.Add(cnt);
        }

        return answer.ToArray();
    }
}