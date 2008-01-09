INSERT INTO `command` (`name`,`security`,`help`) VALUES ('.lookupobject',3,'Syntax: .lookupobject $objname\r\n\r\nLooks up an gameobject by $objname, and returns all matches with their Gameobject ID\'s.');
INSERT INTO `command` (`name`,`security`,`help`) VALUES ('.listcreature',3,'Syntax: .listcreature #creature_id [#max_count]\r\n\r\nOutput creatures with creature id #creature_id found in world. Output creature guids and coordinates sorted by distance from character. Will be output maximum #max_count creatures. If #max_count not provided use 10 as default value.');
INSERT INTO `command` (`name`,`security`,`help`) VALUES ('.listobject',3,'Syntax: .listobject #gameobject_id [#max_count]\r\n\r\nOutput gameobjects with gameobject id #gameobject_id found in world. Output gameobject guids and coordinates sorted by distance from character. Will be output maximum #max_count gameobject. If #max_count not provided use 10 as default value.');
INSERT INTO `command` (`name`,`security`,`help`) VALUES ('.listitem',3,'Syntax: .listitem #item_id [#max_count]\r\n\r\nOutput items with item id #item_id found in all character inventories, mails and auctions. Output item guids, item owner guid, owner account and owner name. Will be output maximum #max_count items. If #max_count not provided use 10 as default value.');
