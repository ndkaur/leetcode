select e.name as name, u.unique_id as unique_id 
from Employees as e 
left join EmployeeUNI as u 
on e.id = u.id;
