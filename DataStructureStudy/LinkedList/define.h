#pragma once
#define SAFE_DELETE(e) if(nullptr != e) delete e
#define SAFE_DELETE_ARR(e) if(nullptr != e) delete[] e