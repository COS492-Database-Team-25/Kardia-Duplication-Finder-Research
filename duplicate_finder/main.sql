drop table duplicates_found where exists (select * from duplicates_found)

create table duplicates_found (
    p_id int,
    given_name varchar(80),
    preferred_name varchar(80),
    surname varchar(80),
    dupe_id int, /* id of found duplicate */
    dupe_id_2 int,
    dupe_id_3 int
)