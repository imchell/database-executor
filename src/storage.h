/**
 * @author Zhaonian Zou <znzou@hit.edu.cn>,
 * School of Computer Science and Technology,
 * Harbin Institute of Technology, China
 */

#pragma once

#include "buffer.h"
#include "catalog.h"
#include "file.h"
#include "types.h"

using namespace std;

namespace badgerdb {

/**
 * Heap file manager for inserting and deleting tuples
 */
class HeapFileManager {
 public:
  /**
   * Insert a tuple to a table
   */
  static RecordId insertTuple(const string& tuple, File& file, BufMgr* bufMgr);

  /**
   * Delete a tuple from a table
   */
  static void deleteTuple(const RecordId& rid, File& file, BufMgr* bugMgr);

  /**
   * Create a tuple from an SQL statement
   */
  static string createTupleFromSQLStatement(const string& sql,
                                            const Catalog* catalog);

  /**
   * Divide a given string by a character
   * @param str original string
   * @param div a char
   * @param outcome the result of division
   */
  static void divideByChar(const string& str, char div, vector<string> &outcome);

  /**
   * Calculate the size of a given content in database (multiply of 4)
   * @param str content
   * @return size
   */
  static int roundUpSize(const string& str);

  /**
   * Get the size of a tuple when it is stored in database
   * @param catalog
   * @param name table name
   * @return size
   */
  int getSizeOfTuple(const Catalog *catalog, const string& name);

  static vector<unsigned char> intToBytes(int paramInt);

  static int bytesToInt(vector<unsigned char> bytes);

  static void concatCharVector(vector<unsigned char> &a, vector<unsigned char> &b);

  static void insertStringIntoCharArray(vector<unsigned char> &originalChar, const string &originalString, int size);

    // static void convertVectorToArray(vector<unsigned char> &v, char *array);


    static void
    insertCharArrayIntoCharArray(vector<unsigned char> &originalChar, vector<unsigned char> &toBeInserted, int size);

    static void convertVectorToArray(vector<unsigned char> &v, char *array);
};
}  // namespace badgerdb