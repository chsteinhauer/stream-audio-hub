#pragma once

struct MatrixInfo
{
    static constexpr int source = 200;
    static constexpr int level  = 200;
    static constexpr int meter  = 130;
    static constexpr int toggle = 70;   // per output (Stream, VOD, Phones…)
    static constexpr int mute   = 60;
    static constexpr int rowHeight  = 60;

    static constexpr const char* sourceTitle = "SOURCE";
    static constexpr const char* levelTitle  = "LEVEL";
    static constexpr const char* meterTitle  = "METER";
    static constexpr const char* muteTitle   = "MUTE";
};

