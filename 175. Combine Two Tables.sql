select a.city, a.state, p.firstName, p.lastName from Person as p
left join address as a
on p.personID = a.personId

