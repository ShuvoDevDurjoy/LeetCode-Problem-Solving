SELECT 
    ll.student_id,
    ll.student_name,
    ll.subject_name, 
    (CASE 
        WHEN counts IS NULL THEN 0 
        ELSE counts 
    END) AS attended_exams 
FROM 
    (
        SELECT 
            student_name, 
            student_id, 
            subject_name 
        FROM 
            Students 
        INNER JOIN 
            Subjects
    ) AS ll 
LEFT JOIN 
    (
        SELECT 
            l.student_id, 
            student_name, 
            l.subject_name, 
            COUNT(CASE 
                    WHEN r.subject_name IS NULL THEN 0 
                    ELSE 1 
                  END) AS counts 
        FROM 
            (
                SELECT 
                    student_id, 
                    student_name, 
                    subject_name 
                FROM 
                    Students 
                INNER JOIN 
                    Subjects
            ) AS l 
        LEFT JOIN 
            Examinations AS r 
        ON 
            l.student_id = r.student_id 
        WHERE 
            l.subject_name = r.subject_name 
        GROUP BY 
            student_id,
            subject_name 
        ORDER BY 
            student_id, 
            subject_name
    ) AS rr 
ON 
    ll.student_id = rr.student_id 
    AND ll.subject_name = rr.subject_name 
ORDER BY 
    student_id, 
    subject_name;
