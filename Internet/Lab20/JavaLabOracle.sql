drop table TestUsers;

CREATE TABLE TestUsers
(
    Id int primary key,
    Name nvarchar(50),
    Age int
);


INSERT INTO TestUsers(Id, Name, Age) VALUES (1, 'name1', 19);
INSERT INTO TestUsers(Id, Name, Age) VALUES (2, 'name2', 22);

select * from TestUsers;

drop procedure SelectUserId;
delimiter //
CREATE procedure SelectUserId (iden int)
BEGIN
    SELECT * FROM TestUsers
    WHERE Id = iden;
END//

call SelectUserId(1)