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
    bool isVal = IsDimensionValid(4,5);
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
    // strncpy(rowString, "--*--",5);
    // AddRowToField(fieldPtr, 1, rowString);
    // strncpy(rowString, "*---*",5);
    // AddRowToField(fieldPtr, 2, rowString);
    // strncpy(rowString, "-----",5);
    // AddRowToField(fieldPtr, 3, rowString);
    int cmp = strncmp(fieldPtr->fieldArray[0], rowString, 5);
    EXPECT_EQ(cmp,0);
}

TEST_F(FieldTest, test_enter_multiple_rows_into_field){
    Field *fieldPtr = CreateField(4,5);
    int cmp = 0;
    char rowString[6] = "-*--*";
    AddRowToField(fieldPtr, 0, rowString);
    cmp = strncmp(fieldPtr->fieldArray[0], rowString, 5);
    EXPECT_EQ(cmp,0);
    strncpy(rowString, "--*--",5);
    AddRowToField(fieldPtr, 1, rowString);
    cmp = strncmp(fieldPtr->fieldArray[1], rowString, 5);
    EXPECT_EQ(cmp,0);
    strncpy(rowString, "*---*",5);
    AddRowToField(fieldPtr, 2, rowString);
    cmp = strncmp(fieldPtr->fieldArray[2], rowString, 5);
    EXPECT_EQ(cmp,0);
    strncpy(rowString, "-----",5);
    AddRowToField(fieldPtr, 3, rowString);
    cmp = strncmp(fieldPtr->fieldArray[3], rowString, 5);
    EXPECT_EQ(cmp,0);    
}

TEST_F(FieldTest, test_add_row_too_long){
    Field *fieldPtr = CreateField(4,5);
    char rowString[10] = "--*---";
    int success = AddRowToField(fieldPtr, 0, rowString);
    EXPECT_EQ(success, 0);
}

TEST_F(FieldTest, test_add_row_too_short){
    Field *fieldPtr = CreateField(4,5);
    char rowString[10] = "--*";
    int success = AddRowToField(fieldPtr, 0, rowString);
    EXPECT_EQ(success, 0);
}

TEST_F(FieldTest, test_add_row_at_index_out_of_bounds){
    int success = 1;
    Field *fieldPtr = CreateField(4,5);
    char rowString[10] = "--*--";
    success = AddRowToField(fieldPtr, 6, rowString);
    EXPECT_EQ(success,0);
}


