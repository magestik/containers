#pragma once

#include "Allocators/DefaultAllocator.h"

// Linear Allocators are very efficient allocators
// They may only be used for Arrays or Stacks
#include "Allocators/FixedSizeLinearAllocator.h"
#include "Allocators/LargeLinearAllocator.h"
#include "Allocators/OptimizedLinearAllocator.h"
