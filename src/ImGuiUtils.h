/*
 *  ImGuiUtils.h
 *  WorldstreamServer
 *
 *  Created by Andreas Borg on 3/21/17
 *  Copyright 2017 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once


#include "ofxImGui.h"

namespace ImGui
{
static auto vector_getter = [](void* vec, int idx, const char** out_text)
{
    auto& vector = *static_cast<std::vector<std::string>*>(vec);
    if (idx < 0 || idx >= static_cast<int>(vector.size())) { return false; }
    *out_text = vector.at(idx).c_str();
    return true;
};
 
static bool Combo(const char* label, int* currIndex, std::vector<std::string>& values)
{
    if (values.empty()) { return false; }
    return Combo(label, currIndex, vector_getter,
        static_cast<void*>(&values), values.size());
}
 
static bool ListBox(const char* label, int* currIndex, std::vector<std::string>& values)
{
    if (values.empty()) { return false; }
    return ListBox(label, currIndex, vector_getter,
        static_cast<void*>(&values), values.size());
}
 
}
