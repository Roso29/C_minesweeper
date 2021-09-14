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
    CreateField(4,4);
}

TEST_F(FieldTest, test_init_field_structure) {
    Field field;
}

TEST_F(FieldTest, test_create_field_structure) {
    Field *fieldPtr = CreateField(4,4);
}

TEST_F(FieldTest, test_field_dimensions) {
    Field *fieldPtr = CreateField(4,5);
    printf("Created field");
    bool isVal = IsDimensionValid(4,5);
    printf("Valid? %d",isVal);
    EXPECT_EQ(fieldPtr->rows, 4);
    EXPECT_EQ(fieldPtr->columns, 5);
}

TEST_F(FieldTest, test_too_many_columns) {
    bool badDimensions = IsDimensionValid(3,101);
    EXPECT_FALSE(badDimensions);
}

TEST_F(FieldTest, test_zero_columns) {
    bool badDimensions = IsDimensionValid(3,0);
    EXPECT_FALSE(badDimensions);
}

TEST_F(FieldTest, test_negative_columns) {
    bool badDimensions = IsDimensionValid(3,-5);
    EXPECT_FALSE(badDimensions);
}

TEST_F(FieldTest, test_too_many_rows) {
    bool badDimensions = IsDimensionValid(101,3);
    EXPECT_FALSE(badDimensions);
}

TEST_F(FieldTest, test_zero_rows) {
    bool badDimensions = IsDimensionValid(0,3);
    EXPECT_FALSE(badDimensions);
}

TEST_F(FieldTest, test_negative_rows) {
    bool badDimensions = IsDimensionValid(-5,3);
    EXPECT_FALSE(badDimensions);
}

TEST_F(FieldTest, test_enter_row_into_field){
    Field *fieldPtr = CreateField(4,5);
    char rowString[6] = "-*--*";
    AddRowToField(fieldPtr, 0, rowString);
    int cmp = strncmp(fieldPtr->fieldArray[0], rowString, 5);
    EXPECT_EQ(cmp,0);
}