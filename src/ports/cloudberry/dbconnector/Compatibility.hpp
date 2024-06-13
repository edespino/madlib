/* ----------------------------------------------------------------------- *//**
 *
 * @file cloudberry/dbconnector/Compatibility.cpp
 *
 *//* ----------------------------------------------------------------------- */

#ifndef MADLIB_GREENPLUM_COMPATIBILITY_HPP
#define MADLIB_GREENPLUM_COMPATIBILITY_HPP

namespace madlib {

namespace dbconnector {

namespace postgres {

namespace {
// No need to make these function accessible outside of the postgres namespace.

#ifndef PG_GET_COLLATION
// Greenplum does not currently have support for collations
#define PG_GET_COLLATION()	InvalidOid
#endif

#ifndef SearchSysCache1
// See madlib_SearchSysCache1()
#define SearchSysCache1(cacheId, key1) \
	SearchSysCache(cacheId, key1, 0, 0, 0)
#endif

} // namespace

inline ArrayType* madlib_construct_array
(
    Datum*  elems,
    int     nelems,
    Oid     elmtype,
    int     elmlen,
    bool    elmbyval,
    char    elmalign
){
    return 
        construct_array(
            elems, nelems, elmtype, elmlen, elmbyval, elmalign);
}

inline ArrayType* madlib_construct_md_array
(
    Datum*  elems,
    bool*   nulls,
    int     ndims,
    int*    dims,
    int*    lbs,
    Oid     elmtype,
    int     elmlen,
    bool    elmbyval,
    char    elmalign
){
    return
        construct_md_array(
            elems, nulls, ndims, dims, lbs, elmtype, elmlen, elmbyval,
            elmalign);
}

} // namespace postgres

} // namespace dbconnector

} // namespace madlib

#endif // defined(MADLIB_GREENPLUM_COMPATIBILITY_HPP)
