SELECT name from (SELECT managerID,count(managerID) as count from Employee group by managerID) as t join Employee where t.managerID = id and count >= 5;
