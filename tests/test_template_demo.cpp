/**
 * Add your test code here.
 */
#include "gtest/gtest.h"

extern "C" {
/**
 * The header for the unit under test should go in this
 * extern C block, as well as any other C file headers
 * that are required.
 */
#include "minesweeper_lib/library.h"
}

class FieldTest : public testing::Test {

    void SetUp() override {
        // Do setup
    }

    void TearDown() override {
        // Do teardown
    }

public:

};

TEST_F(FieldTest, test_CreateField_function) {
    CreateField(4,4,'-');
}

TEST_F(FieldTest, test_init_field_structure) {
    Field field;
}

TEST_F(FieldTest, test_create_field_structure) {
    Field *fieldPtr = CreateField(4,4,'-');
}

TEST_F(FieldTest, test_field_dimensions) {
    Field *fieldPtr = CreateField(4,5,'-');
    
    EXPECT_EQ(fieldPtr->rows, 4);
    EXPECT_EQ(fieldPtr->columns, 5);
}

TEST_F(FieldTest, test_bad_dimensions_given_to_CreateField) {
    Field *fieldPtr = CreateField(10,102,'-');
    EXPECT_TRUE(NULL==fieldPtr);
}
