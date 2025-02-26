def job_sequencing(jobs):

    jobs.sort(key=lambda x: x[2], reverse=True)
    
    max_deadline = max(job[1] for job in jobs)
    
    result = [-1] * max_deadline
    slot = [False] * max_deadline
    
    for i in range(len(jobs)):
        for j in range(min(max_deadline-1, jobs[i][1]-1), -1, -1):
            if not slot[j]:
                result[j] = jobs[i][0]
                slot[j] = True
                break
    
    return [x for x in result if x != -1]

jobs = [(1, 5, 30), (2, 2, 20), (3, 2, 60), (4, 2, 40)]  # (job_id, deadline, profit)
print(f"Job sequence: {job_sequencing(jobs)}")