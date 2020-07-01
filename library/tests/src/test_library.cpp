#include "gtest/gtest.h"
#include "library/library.hpp"

//Tests state transitions
TEST(TestStateMachine, state_transitions)
{
    ASSERT_EQ( library::normal_function(), 1 );
}