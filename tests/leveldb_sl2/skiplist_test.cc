// Copyright (c) 2011 The LevelDB Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file. See the AUTHORS file for names of contributors.

#include "db/skiplist.h"

#include <atomic>
#include <set>

// #include "gtest/gtest.h"
// #include "leveldb/env.h"
// #include "port/port.h"
// #include "port/thread_annotations.h"
#include "include/db.h"
#include "util/arena.h"
// #include "util/hash.h"
// #include "util/random.h"
// #include "util/testutil.h"

// namespace leveldb {

typedef uint64_t Key;

struct Comparator {
  int operator()(const Key& a, const Key& b) const {
    if (a < b) {
      return -1;
    } else if (a > b) {
      return +1;
    } else {
      return 0;
    }
  }
};

void func1() {
  leveldb::Arena arena;
  // Comparator cmp;
  // SkipList<Key, Comparator> list(cmp, &arena);
  // // ASSERT_TRUE(!list.Contains(10));

  // SkipList<Key, Comparator>::Iterator iter(&list);
  // // ASSERT_TRUE(!iter.Valid());
  // iter.SeekToFirst();
  // // ASSERT_TRUE(!iter.Valid());
  // iter.Seek(100);
  // // ASSERT_TRUE(!iter.Valid());
  // iter.SeekToLast();
  // // ASSERT_TRUE(!iter.Valid());
}


int main(int argc, char** argv) {
  func1();
  // testing::InitGoogleTest(&argc, argv);
  // return RUN_ALL_TESTS();
}
// }  // namespace leveldb