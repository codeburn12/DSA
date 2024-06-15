nth Highest/lowest Salary
~~~~sql
SELECT salary
FROM employees
ORDER BY salary DESC/ASC
LIMIT 1 OFFSET n-1;

SELECT MIN/MAX(salary)
FROM (SELECT salary
      FROM employees
      ORDER BY salary DESC/ASC
      LIMIT n) AS top_salaries;

~~~~
duplicate records in a table
~~~~sql
SELECT column1, column2, COUNT(*)
FROM table_name
GROUP BY column1, column2
HAVING COUNT(*) > 1;
~~~~
 count the number of employees in each department
~~~~sql
SELECT department_id, COUNT(*) AS EmployeeCount
FROM Employee
GROUP BY department_id;
~~~~
top 5 highest-paid employees
~~~~sql
SELECT TOP 5 employee_id, employee_name, salary
FROM Employee
ORDER BY salary DESC;

SELECT * FROM Employee ORDER BY salary DESC LIMIT 5;
~~~~
find the department with the highest number of employees
~~~~sql
SELECT department_id, COUNT(*) AS EmployeeCount
FROM Employee
GROUP BY department_id
ORDER BY EmployeeCount DESC
LIMIT 1;
~~~~
find employees who earn more than the average salary
~~~~sql
SELECT employee_id, employee_name, salary
FROM Employee
WHERE salary > (SELECT AVG(salary) FROM Employee);
~~~~
find the employees who work in more than one department
~~~~sql
SELECT employee_id
FROM EmployeeDepartments
GROUP BY employee_id
HAVING COUNT(department_id) > 1;
~~~~
find all departments that have more than 5 employees
~~~~sql
SELECT department_id, COUNT(employee_id) AS EmployeeCount
FROM Employee
GROUP BY department_id
HAVING COUNT(employee_id) > 5;
~~~~
employees with the highest salary in each department
~~~~sql
SELECT department_id, employee_id, employee_name, salary
FROM Employee
WHERE (department_id, salary) IN (
    SELECT department_id, MAX(salary)
    FROM Employee
    GROUP BY department_id
);
~~~~
show one row twice in results from a table
~~~~sql
SELECT * FROM Student 
UNION ALL
SELECT * FROM Student ORDER BY STUDENT_ID;
~~~~
fetch the first 50% records from a table
~~~~sql
SELECT * FROM Student WHERE STUDENT_ID <= (SELECT COUNT(STUDENT_ID)/2 FROM Student);
~~~~
the last record from a table
~~~~sql
SELECT * FROM Student WHERE STUDENT_ID = (SELECT MAX(STUDENT_ID) FROM STUDENT);
~~~~
fetch the first row of a table
~~~~sql
SELECT * FROM Student WHERE STUDENT_ID = (SELECT MIN(STUDENT_ID) FROM Student);
~~~~
the last five records from a table
~~~~sql
SELECT * 
FROM (
    SELECT * 
    FROM Student 
    ORDER BY STUDENT_ID DESC 
    LIMIT 5
) AS subquery
ORDER BY STUDENT_ID;
~~~~
total number of employees in each department along with the department name
~~~~sql
SELECT Department.department_name, COUNT(Employee.employee_id) AS EmployeeCount
FROM Department
INNER JOIN Employee ON Department.department_id = Employee.department_id
GROUP BY Department.department_name;
~~~~
find the names of employees who are also managers
~~~~sql
SELECT DISTINCT Employee.employee_name
FROM Employee
INNER JOIN Employee AS Manager ON Employee.employee_id = Manager.manager_id;
~~~~
list all employees along with their manager's name
~~~~sql
SELECT e.employee_id, e.employee_name, m.employee_name AS manager_name
FROM Employee e
LEFT JOIN Employee m ON e.manager_id = m.employee_id;
~~~~
find the department names that have no employees
~~~~sql
SELECT d.department_name
FROM Department d
LEFT JOIN Employee e ON d.department_id = e.department_id
WHERE e.employee_id IS NULL;
~~~~
 details of employees who share the same salary
~~~~sql
SELECT e.id, e.name, e.salary, e.department
FROM employees e
JOIN (
    SELECT salary
    FROM employees
    GROUP BY salary
    HAVING COUNT(*) > 1
) dup ON e.salary = dup.salary;
~~~~