use java_ee_lab;

Create table WSREF (
id int IDENTITY(1,1) primary key,
url nvarchar(100),
description nvarchar(100),
minus int,
plus int
)

Create table WSREFCOMMENT (
id int IDENTITY(1,1) primary key,
refId int,
sessionId nvarchar(100),
stamp Date,
plus int,
comment nvarchar(100)
)

GRANT SELECT ON dbo.WSREFCOMMENT TO JavaUser;

GRANT SELECT ON dbo.UWSR TO JavaUser;

INSERT INTO WSREF(url, description, plus, minus) VALUES (1, 'name1', 0,0);


drop database javaLab24;
