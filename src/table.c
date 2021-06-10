#include "table.h"

// const int table_v[11] = {0, 3277, 6554, 9830, 13107, 16384, 19661, 22938,
// 26214, 29491, 32768 };
const int16_t table_v[11] = { 0,    1638,  3277,  4915,  6554, 8192,
                              9830, 11469, 13107, 14746, 16384 };


const int16_t table_vv[100] = {
    0,    16,   33,   49,   66,   82,   98,   115,  131,  147,  164,  180,
    197,  213,  229,  246,  262,  279,  295,  311,  328,  344,  360,  377,
    393,  410,  426,  442,  459,  475,  492,  508,  524,  541,  557,  573,
    590,  606,  623,  639,  655,  672,  688,  705,  721,  737,  754,  770,
    786,  803,  819,  836,  852,  868,  885,  901,  918,  934,  950,  967,
    983,  999,  1016, 1032, 1049, 1065, 1081, 1098, 1114, 1130, 1147, 1163,
    1180, 1196, 1212, 1229, 1245, 1262, 1278, 1294, 1311, 1327, 1343, 1360,
    1376, 1393, 1409, 1425, 1442, 1458, 1475, 1491, 1507, 1524, 1540, 1556,
    1573, 1589, 1606, 1622
};


const int16_t table_hzv[76] = {
    205,  217,  230,   244,   258,   273,   290,   307,   325,   344,  365,
    387,  410,  434,   460,   487,   516,   547,   579,   614,   650,  689,
    730,  773,  819,   868,   920,   974,   1032,  1094,  1159,  1227, 1300,
    1378, 1460, 1546,  1638,  1736,  1839,  1948,  2064,  2187,  2317, 2455,
    2601, 2755, 2919,  3093,  3277,  3472,  3678,  3897,  4129,  4374, 4634,
    4910, 5202, 5511,  5839,  6186,  6554,  6943,  7356,  7794,  8257, 8748,
    9268, 9819, 10403, 11022, 11677, 12372, 13107, 13887, 14712, 15587
};


//>>> for i in range(0,256):
//...     print '%.0f, ' % (math.pow(i/64.,4)*16384./256.)
const int16_t table_exp[256] = {
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    0,     0,     0,     0,     0,     0,     0,     0,     0,     1,     1,
    1,     1,     1,     1,     2,     2,     2,     3,     3,     4,     4,
    5,     5,     6,     6,     7,     8,     9,     10,    11,    12,    13,
    14,    16,    17,    19,    20,    22,    24,    26,    28,    30,    32,
    35,    38,    40,    43,    46,    49,    53,    56,    60,    64,    68,
    72,    77,    82,    86,    92,    97,    103,   108,   114,   121,   127,
    134,   141,   149,   156,   164,   172,   181,   190,   199,   209,   219,
    229,   239,   250,   262,   273,   285,   298,   311,   324,   338,   352,
    366,   381,   397,   413,   429,   446,   464,   482,   500,   519,   538,
    559,   579,   600,   622,   644,   667,   691,   715,   740,   765,   791,
    818,   845,   873,   902,   931,   961,   992,   1024,  1056,  1090,  1123,
    1158,  1194,  1230,  1267,  1305,  1344,  1383,  1424,  1465,  1508,  1551,
    1595,  1640,  1686,  1733,  1781,  1830,  1880,  1931,  1983,  2036,  2090,
    2146,  2202,  2259,  2318,  2377,  2438,  2500,  2563,  2627,  2693,  2760,
    2827,  2897,  2967,  3039,  3112,  3186,  3262,  3339,  3417,  3497,  3578,
    3660,  3744,  3829,  3916,  4005,  4094,  4185,  4278,  4373,  4468,  4566,
    4665,  4765,  4868,  4971,  5077,  5184,  5293,  5403,  5516,  5630,  5745,
    5863,  5982,  6104,  6227,  6351,  6478,  6607,  6737,  6870,  7004,  7140,
    7279,  7419,  7561,  7706,  7852,  8000,  8151,  8304,  8459,  8616,  8775,
    8936,  9100,  9266,  9434,  9604,  9777,  9952,  10129, 10309, 10491, 10675,
    10862, 11051, 11243, 11437, 11634, 11833, 12035, 12240, 12447, 12656, 12869,
    13083, 13301, 13521, 13744, 13970, 14199, 14430, 14664, 14901, 15141, 15384,
    15629, 15878, 16129
};


// "Prime" patterns from Noise Engineering Numeric Repetitor
// see manual https://www.noiseengineering.us/shop/numeric-repetitor
// 1000100010001000
// 1000100010001010
// 1000100010010010
// 1000100010010100
// 1000100010100010
// 1000100010100100
// 1000100100010010
// 1000100100010100
// 1000100100100010
// 1000100100100100
// 1000101010001010
// 1000101010101010
// 1001001010010010
// 1001001010101010
// 1001010010101010
// 1001010100101010
// 1000001010000010
// 1000001010001010
// 1000001010010010
// 1000001010100010
// 1000010010000100
// 1000010010001010
// 1000010010010010
// 1000010010010100
// 1000010010100010
// 1000010010100100
// 1000010100001010
// 1000010100010010
// 1000010100010100
// 1000010100100010
// 1000010100100100
// 1000010101000100
const uint16_t table_nr[32] = { 0x8888, 0x888A, 0x8892, 0x8894, 0x88A2, 0x88A4,
                                0x8912, 0x8914, 0x8922, 0x8924, 0x8A8A, 0x8AAA,
                                0x9292, 0x92AA, 0x94AA, 0x952A, 0x8282, 0x828A,
                                0x8292, 0x82A2, 0x8484, 0x848A, 0x8492, 0x8494,
                                0x84A2, 0x84A4, 0x850A, 0x8512, 0x8514, 0x8522,
                                0x8524, 0x8544 };

// scales for N.S op
const uint8_t table_n_s[9][7] = {
    { 0, 2, 4, 5, 7, 9, 11 },  // Major
    { 0, 2, 3, 5, 7, 8, 10 },  // Natural Minor
    { 0, 2, 3, 5, 7, 8, 11 },  // Harmonic Minor
    { 0, 2, 3, 5, 7, 9, 11 },  // Melodic Minor
    { 0, 2, 3, 5, 7, 9, 10 },  // Dorian
    { 0, 1, 3, 5, 7, 8, 10 },  // Phrygian
    { 0, 2, 4, 6, 7, 9, 11 },  // Lydian
    { 0, 2, 4, 5, 7, 9, 10 },  // Myxolidian
    { 0, 1, 3, 5, 6, 8, 10 },  // Locrian
};

// chords for N.C op
const uint8_t table_n_c[13][4] = {
    { 0, 4, 7, 11 },  // Major 7th       - 0
    { 0, 3, 7, 10 },  // Minor 7th       - 1
    { 0, 4, 7, 10 },  // Dominant 7th    - 2
    { 0, 3, 6, 9 },   // Diminished 7th  - 3
    { 0, 4, 8, 10 },  // Augmented 7th   - 4
    { 0, 4, 6, 10 },  // Dominant 7b5    - 5
    { 0, 3, 6, 10 },  // Minor 7b5       - 6
    { 0, 4, 8, 11 },  // Major 7#5       - 7
    { 0, 3, 7, 11 },  // Minor major 7th - 8
    { 0, 3, 6, 11 },  // Dim Major 7th   - 9
    { 0, 4, 7, 9 },   // Major 6th       - 10
    { 0, 3, 7, 9 },   // Minor 6th       - 11
    { 0, 5, 7, 10 },  // 7th sus 4       - 12
};

// chord scales for N.CS op - values are indices into table_n_c
const uint8_t table_n_cs[9][7] = {
    { 0, 1, 1, 0, 2, 1, 6 },  // Major
    { 1, 6, 0, 1, 1, 0, 2 },  // Natural Minor
    { 8, 6, 7, 1, 2, 0, 3 },  // Harmonic Minor
    { 8, 1, 7, 2, 2, 6, 6 },  // Melodic Minor
    { 1, 1, 0, 2, 1, 6, 0 },  // Dorian
    { 1, 0, 2, 1, 6, 0, 1 },  // Phrygian
    { 0, 2, 1, 6, 0, 1, 1 },  // Lydian
    { 6, 0, 1, 1, 0, 2, 1 },  // Locrian
    { 2, 1, 6, 0, 1, 1, 0 },  // Myxolydian
};

// preset bit mask scales for N.B and N.BX
const uint16_t table_n_b[] = {
    0b101011010101,  // ionian (major)
    0b101101010110,  // dorian
    0b110101011010,  // phrygian
    0b101010110101,  // lydian
    0b101011010110,  // mixolydian
    0b101101011010,  // aeolean (natural minor)
    0b110101101010,  // locrian
    0b101101010101,  // melodic minor
    0b101101011001,  // harmonic minor
    0b101010010100,  // major pentatonic
    0b100101010010,  // minor pentatonic
    0b101010101010,  // whole note (1st messiaen mode)
    0b110110110110,  // octatonic (half-whole, 2nd messiaen mode)
    0b101101101101,  // octatonic (whole-half)
    0b101110111011,  // 3rd messiaen mode
    0b111001111001,  // 4th messiaen mode
    0b110001110001,  // 5th messiaen mode
    0b101011101011,  // 6th mesiaen mode
    0b111101111101,  // 7th messiaen mode
    0b100110011001,  // augmented
};
