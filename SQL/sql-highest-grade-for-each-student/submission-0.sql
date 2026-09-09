-- Write your query below
select student_id,
MIN(exam_id) as exam_id,
score
from  exam_results
where (student_id,score) IN(
    select student_id,max(score) 
    from exam_results
    group by student_id
)
group by student_id,score
order by student_id ASC


