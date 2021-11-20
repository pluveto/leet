```sql
CREATE TABLE 病例基本信息表(
    病例号   integer primary key,
    省      varchar(50),
    市      varchar(50),
    区      varchar(50),
    日期    date,
    性别    varchar(50),
    年龄    smallint,
    患者信息 text,
    其他信息 text,
    信息来源 varchar(50)
);
```