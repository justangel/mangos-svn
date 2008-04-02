/* QueryResultSqlite.cpp
 *
 * Copyright (C) 2004 Wow Daemon
 * Copyright (C) 2005 MaNGOS <https://opensvn.csie.org/traccgi/MaNGOS/trac.cgi/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "DatabaseEnv.h"

QueryResultSqlite::QueryResultSqlite(char **tableData, uint32 rowCount, uint32 fieldCount) :
QueryResult(rowCount, fieldCount), mTableData(tableData), mTableIndex(0)
{
    mCurrentRow = new Field[mFieldCount];
    ASSERT(mCurrentRow);

    for (uint32 i = 0; i < mFieldCount; i++)
    {
        mCurrentRow[i].SetName(mTableData[i]);
        // will change this to support datatypes eventually if needed
        mCurrentRow[i].SetType(Field::DB_TYPE_UNKNOWN);
    }
}


QueryResultSqlite::~QueryResultSqlite()
{
    EndQuery();
}


bool QueryResultSqlite::NextRow()
{
    int startIndex;
    uint32 i;

    if (!mTableData)
        return false;

    if (mTableIndex >= mRowCount)
    {
        EndQuery();
        return false;
    }

    startIndex = (mTableIndex + 1) * mFieldCount;
    for (i = 0; i < mFieldCount; i++)
    {
        mCurrentRow[i].SetValue(mTableData[startIndex + i]);
    }

    ++mTableIndex;
    return true;
}


void QueryResultSqlite::EndQuery()
{
    if (mCurrentRow)
    {
        delete [] mCurrentRow;
        mCurrentRow = 0;
    }
    if (mTableData)
    {
        sqlite_free_table(mTableData);
        mTableData = 0;
    }
}


enum Field::DataTypes QueryResultSqlite::ConvertNativeType(const char* sqliteType) const
{
    if (sqliteType)
    {
        switch (*sqliteType)
        {
            case 'S':
                return Field::DB_TYPE_STRING;
            case 'I':
                return Field::DB_TYPE_INTEGER;
            case 'F':
                return Field::DB_TYPE_FLOAT;
            default:
                return Field::DB_TYPE_UNKNOWN;
        };
    }
    return Field::DB_TYPE_UNKNOWN;
}