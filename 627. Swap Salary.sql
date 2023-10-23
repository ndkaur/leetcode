update Salary 
set sex = 
case sex 
when 'f' then 'm' 
else 'f' 
end;


UPDATE Salary 
SET sex = (CASE WHEN sex = 'f' THEN 'm' ELSE 'f' END) 