xof 0303txt 0032
template Frame {
 <3d82ab46-62da-11cf-ab39-0020af71e433>
 [...]
}

template Matrix4x4 {
 <f6f23f45-7686-11cf-8f52-0040333594a3>
 array FLOAT matrix[16];
}

template FrameTransformMatrix {
 <f6f23f41-7686-11cf-8f52-0040333594a3>
 Matrix4x4 frameMatrix;
}

template ObjectMatrixComment {
 <95a48e28-7ef4-4419-a16a-ba9dbdf0d2bc>
 Matrix4x4 objectMatrix;
}

template Vector {
 <3d82ab5e-62da-11cf-ab39-0020af71e433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template MeshFace {
 <3d82ab5f-62da-11cf-ab39-0020af71e433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template Mesh {
 <3d82ab44-62da-11cf-ab39-0020af71e433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

template MeshNormals {
 <f6f23f43-7686-11cf-8f52-0040333594a3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template Coords2d {
 <f6f23f44-7686-11cf-8f52-0040333594a3>
 FLOAT u;
 FLOAT v;
}

template MeshTextureCoords {
 <f6f23f40-7686-11cf-8f52-0040333594a3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template ColorRGBA {
 <35ff44e0-6c7c-11cf-8f52-0040333594a3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <d3e16e81-7835-11cf-8f52-0040333594a3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template Material {
 <3d82ab4d-62da-11cf-ab39-0020af71e433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshMaterialList {
 <f6f23f42-7686-11cf-8f52-0040333594a3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material <3d82ab4d-62da-11cf-ab39-0020af71e433>]
}

template TextureFilename {
 <a42790e1-7810-11cf-8f52-0040333594a3>
 STRING filename;
}


Frame Cactus_Leafy_05 {
 

 FrameTransformMatrix relative {
  0.393701,0.000000,0.000000,0.000000,0.000000,0.393701,0.000000,0.000000,0.000000,-0.000000,0.393701,0.000000,0.000000,0.000000,0.000000,1.000000;;
 }

 ObjectMatrixComment object {
  1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
 }

 Mesh mesh_C {
  184;
  0.663070;0.883390;1.365540;,
  0.172220;0.857180;1.541850;,
  0.775470;1.090740;1.570490;,
  0.226530;1.226850;2.053410;,
  0.495460;1.311210;1.894580;,
  0.105640;0.302650;0.888380;,
  0.791880;0.397390;0.731760;,
  0.820720;0.313410;-0.112710;,
  1.154700;0.884530;1.017040;,
  1.222420;1.332210;1.558040;,
  1.554650;1.263610;1.329510;,
  1.434110;0.897730;0.471050;,
  1.615890;1.105720;0.551670;,
  1.689420;1.339940;0.950930;,
  1.523650;0.879520;-0.215030;,
  1.701070;1.108140;0.509230;,
  1.965890;1.338710;0.198780;,
  2.027430;1.256620;-0.287800;,
  -0.348040;0.849220;1.497570;,
  -0.417630;1.050420;1.726280;,
  -0.079130;1.291790;1.969610;,
  -0.602550;0.350270;0.913850;,
  -0.911570;0.814700;1.286860;,
  -1.242240;1.169080;1.694730;,
  -0.867820;1.261570;1.830990;,
  -1.321910;0.804590;0.830940;,
  -1.490320;1.000740;0.957280;,
  -1.474370;1.233010;1.364060;,
  -0.876160;0.256070;0.108870;,
  -1.583020;0.774530;0.190640;,
  -1.583500;0.997130;0.938130;,
  -2.112490;1.116700;0.252790;,
  -1.933800;1.206910;0.708000;,
  -0.126300;0.268010;-0.896770;,
  0.287870;0.827350;-1.522290;,
  -0.231600;0.796870;-1.566240;,
  0.343160;1.026170;-1.756910;,
  -0.011440;1.235500;-2.006890;,
  -0.311600;1.146470;-2.088420;,
  0.576710;0.365260;-0.924380;,
  0.852200;0.839350;-1.311250;,
  1.157180;1.204240;-1.729740;,
  0.777260;1.265720;-1.868270;,
  1.261740;0.871980;-0.855650;,
  1.415860;1.075840;-0.987910;,
  1.383800;1.294280;-1.401340;,
  1.509040;1.079450;-0.968760;,
  1.843230;1.320380;-0.745280;,
  -0.723240;0.793180;-1.390250;,
  -0.849940;0.985840;-1.601110;,
  -0.586030;1.216080;-1.931860;,
  -0.817720;0.318130;-0.742290;,
  -1.214070;0.769520;-1.041430;,
  -1.312990;1.195080;-1.595320;,
  -1.639720;1.109710;-1.364520;,
  -1.494280;0.778840;-0.495770;,
  -1.690350;0.970860;-0.582300;,
  -1.779990;1.187360;-0.988210;,
  -1.775530;0.968450;-0.539850;,
  -2.056450;1.188590;-0.236060;,
  -0.005830;0.159320;-0.002330;,
  0.790310;1.055410;1.599830;,
  0.177520;0.820650;1.572950;,
  0.678400;0.847770;1.394270;,
  0.513820;1.276420;1.922550;,
  0.231480;1.187690;2.081180;,
  0.841180;0.269740;-0.114530;,
  0.811490;0.356280;0.747740;,
  0.109740;0.258860;0.908280;,
  1.180320;0.849130;1.037540;,
  1.579810;1.226010;1.346340;,
  1.239510;1.302320;1.591870;,
  1.464980;0.861800;0.480310;,
  1.647010;1.071920;0.566450;,
  1.720790;1.304470;0.960350;,
  1.552840;0.841200;-0.218080;,
  1.732010;1.071550;0.515050;,
  2.058510;1.219840;-0.291120;,
  2.002870;1.309220;0.208430;,
  -0.422060;1.014430;1.758150;,
  -0.353090;0.812910;1.528960;,
  -0.087350;1.256100;2.001050;,
  -0.928660;0.777850;1.312930;,
  -0.614450;0.308160;0.934220;,
  -1.259690;1.130050;1.717120;,
  -0.873650;1.230900;1.867810;,
  -1.514300;0.965080;0.979260;,
  -1.347050;0.766950;0.847720;,
  -1.499850;1.195630;1.380900;,
  -1.609820;0.734610;0.194900;,
  -0.893970;0.211310;0.112050;,
  -1.609420;0.958620;0.951370;,
  -2.140870;1.077910;0.257230;,
  -1.965030;1.175120;0.726560;,
  -0.234240;0.759140;-1.596240;,
  0.295530;0.790580;-1.552610;,
  -0.127200;0.223470;-0.915370;,
  0.350190;0.989670;-1.787700;,
  -0.000660;1.199570;-2.037270;,
  -0.313710;1.106250;-2.115020;,
  0.591780;0.323460;-0.943250;,
  0.871900;0.803060;-1.336240;,
  1.177390;1.165900;-1.750990;,
  0.785290;1.234470;-1.904170;,
  1.289400;0.835570;-0.871110;,
  1.442340;1.041350;-1.008850;,
  1.411900;1.258330;-1.417100;,
  1.537650;1.042520;-0.980880;,
  1.876660;1.290370;-0.762930;,
  -0.735960;0.755720;-1.417910;,
  -0.862190;0.948690;-1.629390;,
  -0.601830;1.179250;-1.958770;,
  -0.834220;0.275330;-0.757320;,
  -1.237080;0.731780;-1.060850;,
  -1.662110;1.069930;-1.380200;,
  -1.327870;1.163050;-1.628240;,
  -1.522690;0.740720;-0.504130;,
  -1.718970;0.934510;-0.596040;,
  -1.808740;1.149490;-0.996540;,
  -1.803780;0.929590;-0.544560;,
  -2.091230;1.156270;-0.244800;,
  0.000000;0.000000;0.000000;,
  0.775470;1.090740;1.570490;,
  0.495460;1.311210;1.894580;,
  0.226530;1.226850;2.053410;,
  1.222420;1.332210;1.558040;,
  1.554650;1.263610;1.329510;,
  1.434110;0.897730;0.471050;,
  1.615890;1.105720;0.551670;,
  1.689420;1.339940;0.950930;,
  1.701070;1.108140;0.509230;,
  1.965890;1.338710;0.198780;,
  2.027430;1.256620;-0.287800;,
  -0.079130;1.291790;1.969610;,
  -0.417630;1.050420;1.726280;,
  -0.867820;1.261570;1.830990;,
  -1.242240;1.169080;1.694730;,
  -1.490320;1.000740;0.957280;,
  -1.321910;0.804590;0.830940;,
  -1.474370;1.233010;1.364060;,
  -1.583500;0.997130;0.938130;,
  -1.933800;1.206910;0.708000;,
  -2.112490;1.116700;0.252790;,
  -0.311600;1.146470;-2.088420;,
  -0.011440;1.235500;-2.006890;,
  0.343160;1.026170;-1.756910;,
  0.777260;1.265720;-1.868270;,
  1.157180;1.204240;-1.729740;,
  1.415860;1.075840;-0.987910;,
  1.261740;0.871980;-0.855650;,
  1.383800;1.294280;-1.401340;,
  1.509040;1.079450;-0.968760;,
  1.843230;1.320380;-0.745280;,
  -0.849940;0.985840;-1.601110;,
  -0.586030;1.216080;-1.931860;,
  -1.312990;1.195080;-1.595320;,
  -1.639720;1.109710;-1.364520;,
  -1.494280;0.778840;-0.495770;,
  -1.690350;0.970860;-0.582300;,
  -1.779990;1.187360;-0.988210;,
  -1.775530;0.968450;-0.539850;,
  -2.056450;1.188590;-0.236060;,
  -0.810400;1.022320;0.085450;,
  -0.664160;1.575360;0.055720;,
  -0.319770;1.578330;-0.576620;,
  -0.371940;1.026100;-0.719600;,
  -0.180870;1.054640;0.751040;,
  -0.169690;1.600740;0.578510;,
  0.646660;1.078390;0.357350;,
  0.480310;1.619400;0.269280;,
  0.528570;1.060750;-0.551560;,
  0.387550;1.605540;-0.444630;,
  -0.147660;0.351720;-1.038650;,
  -0.729030;0.335040;-0.762070;,
  -0.940850;0.335640;-0.209050;,
  -0.855570;0.348110;0.429190;,
  -0.511830;0.367480;0.909650;,
  0.119650;0.424430;1.027230;,
  0.702190;0.408510;0.751130;,
  0.929580;0.453820;0.195200;,
  0.802230;0.394550;-0.436670;,
  0.484990;0.376070;-0.920600;,
  0.025890;0.247030;-0.008160;,
  -0.092470;1.796970;-0.042900;;
  280;
  3;0,1,2;,
  3;1,3,4;,
  3;4,2,1;,
  3;5,6,7;,
  3;0,8,6;,
  3;0,2,8;,
  3;2,9,10;,
  3;10,8,2;,
  3;11,7,6;,
  3;6,8,11;,
  3;11,8,12;,
  3;8,10,13;,
  3;13,12,8;,
  3;11,14,7;,
  3;11,15,14;,
  3;15,16,17;,
  3;17,14,15;,
  3;18,19,1;,
  3;1,19,20;,
  3;20,3,1;,
  3;5,18,1;,
  3;21,22,18;,
  3;18,22,19;,
  3;19,22,23;,
  3;23,24,19;,
  3;25,26,22;,
  3;22,26,27;,
  3;27,23,22;,
  3;28,29,25;,
  3;25,29,30;,
  3;30,29,31;,
  3;31,32,30;,
  3;33,34,35;,
  3;34,36,35;,
  3;35,36,37;,
  3;37,38,35;,
  3;34,33,39;,
  3;39,40,34;,
  3;34,40,36;,
  3;36,40,41;,
  3;41,42,36;,
  3;39,43,40;,
  3;43,44,40;,
  3;40,44,45;,
  3;45,41,40;,
  3;43,14,46;,
  3;46,14,17;,
  3;17,47,46;,
  3;33,35,48;,
  3;48,35,49;,
  3;35,38,50;,
  3;50,49,35;,
  3;33,51,28;,
  3;48,49,52;,
  3;49,53,54;,
  3;54,52,49;,
  3;28,55,29;,
  3;51,52,55;,
  3;55,52,56;,
  3;52,54,57;,
  3;57,56,52;,
  3;55,58,29;,
  3;58,59,31;,
  3;31,29,58;,
  3;33,48,51;,
  3;33,7,39;,
  3;7,43,39;,
  3;5,0,6;,
  3;5,28,21;,
  3;28,25,21;,
  3;25,22,21;,
  3;28,51,55;,
  3;48,52,51;,
  3;7,14,43;,
  3;1,0,5;,
  3;5,21,18;,
  3;7,60,5;,
  3;7,33,60;,
  3;33,28,60;,
  3;60,28,5;,
  3;61,62,63;,
  3;64,65,62;,
  3;62,61,64;,
  3;66,67,68;,
  3;67,69,63;,
  3;69,61,63;,
  3;70,71,61;,
  3;61,69,70;,
  3;67,66,72;,
  3;72,69,67;,
  3;73,69,72;,
  3;74,70,69;,
  3;69,73,74;,
  3;66,75,72;,
  3;75,76,72;,
  3;77,78,76;,
  3;76,75,77;,
  3;62,79,80;,
  3;81,79,62;,
  3;62,65,81;,
  3;62,80,68;,
  3;80,82,83;,
  3;79,82,80;,
  3;84,82,79;,
  3;79,85,84;,
  3;82,86,87;,
  3;88,86,82;,
  3;82,84,88;,
  3;87,89,90;,
  3;91,89,87;,
  3;92,89,91;,
  3;91,93,92;,
  3;94,95,96;,
  3;94,97,95;,
  3;98,97,94;,
  3;94,99,98;,
  3;100,96,95;,
  3;95,101,100;,
  3;97,101,95;,
  3;102,101,97;,
  3;97,103,102;,
  3;101,104,100;,
  3;101,105,104;,
  3;106,105,101;,
  3;101,102,106;,
  3;107,75,104;,
  3;77,75,107;,
  3;107,108,77;,
  3;109,94,96;,
  3;110,94,109;,
  3;111,99,94;,
  3;94,110,111;,
  3;90,112,96;,
  3;113,110,109;,
  3;114,115,110;,
  3;110,113,114;,
  3;89,116,90;,
  3;116,113,112;,
  3;117,113,116;,
  3;118,114,113;,
  3;113,117,118;,
  3;89,119,116;,
  3;92,120,119;,
  3;119,89,92;,
  3;112,109,96;,
  3;100,66,96;,
  3;100,104,66;,
  3;67,63,68;,
  3;83,90,68;,
  3;83,87,90;,
  3;83,82,87;,
  3;116,112,90;,
  3;112,113,109;,
  3;104,75,66;,
  3;63,62,68;,
  3;80,83,68;,
  3;68,121,66;,
  3;121,96,66;,
  3;121,90,96;,
  3;68,90,121;,
  3;64,61,122;,
  3;122,123,64;,
  3;65,64,123;,
  3;123,124,65;,
  3;61,71,125;,
  3;125,122,61;,
  3;71,70,126;,
  3;126,125,71;,
  3;73,72,127;,
  3;127,128,73;,
  3;74,73,128;,
  3;128,129,74;,
  3;70,74,129;,
  3;129,126,70;,
  3;72,76,130;,
  3;130,127,72;,
  3;76,78,131;,
  3;131,130,76;,
  3;78,77,132;,
  3;132,131,78;,
  3;81,65,124;,
  3;124,133,81;,
  3;79,81,133;,
  3;133,134,79;,
  3;84,85,135;,
  3;135,136,84;,
  3;85,79,134;,
  3;134,135,85;,
  3;87,86,137;,
  3;137,138,87;,
  3;88,84,136;,
  3;136,139,88;,
  3;86,88,139;,
  3;139,137,86;,
  3;91,87,138;,
  3;138,140,91;,
  3;92,93,141;,
  3;141,142,92;,
  3;93,91,140;,
  3;140,141,93;,
  3;98,99,143;,
  3;143,144,98;,
  3;97,98,144;,
  3;144,145,97;,
  3;102,103,146;,
  3;146,147,102;,
  3;103,97,145;,
  3;145,146,103;,
  3;104,105,148;,
  3;148,149,104;,
  3;106,102,147;,
  3;147,150,106;,
  3;105,106,150;,
  3;150,148,105;,
  3;107,104,149;,
  3;149,151,107;,
  3;77,108,152;,
  3;152,132,77;,
  3;108,107,151;,
  3;151,152,108;,
  3;111,110,153;,
  3;153,154,111;,
  3;99,111,154;,
  3;154,143,99;,
  3;110,115,155;,
  3;155,153,110;,
  3;115,114,156;,
  3;156,155,115;,
  3;117,116,157;,
  3;157,158,117;,
  3;118,117,158;,
  3;158,159,118;,
  3;114,118,159;,
  3;159,156,114;,
  3;116,119,160;,
  3;160,157,116;,
  3;119,120,161;,
  3;161,160,119;,
  3;120,92,142;,
  3;142,161,120;,
  3;162,163,164;,
  3;164,165,162;,
  3;166,167,163;,
  3;163,162,166;,
  3;168,169,167;,
  3;167,166,168;,
  3;170,171,169;,
  3;169,168,170;,
  3;171,170,164;,
  3;165,172,173;,
  3;174,162,165;,
  3;165,173,174;,
  3;162,174,175;,
  3;176,166,162;,
  3;162,175,176;,
  3;166,176,177;,
  3;178,168,166;,
  3;166,177,178;,
  3;168,178,179;,
  3;180,170,168;,
  3;168,179,180;,
  3;170,180,181;,
  3;172,165,170;,
  3;170,181,172;,
  3;172,182,173;,
  3;173,182,174;,
  3;174,182,175;,
  3;175,182,176;,
  3;176,182,177;,
  3;177,182,178;,
  3;178,182,179;,
  3;179,182,180;,
  3;180,182,181;,
  3;181,182,172;,
  3;163,167,183;,
  3;183,169,171;,
  3;170,165,164;,
  3;183,171,164;,
  3;167,169,183;,
  3;164,163,183;;

  MeshNormals normals {
   184;
   -0.806719;1.874518;-1.512126;,
   -0.278519;1.923506;-1.635222;,
   -0.330921;2.485195;-0.407198;,
   0.006434;2.446360;0.683004;,
   0.432933;2.502792;0.011473;,
   -0.216118;2.304116;-1.046790;,
   -1.030435;2.164662;-0.838888;,
   -1.085703;2.295358;0.062014;,
   -1.352593;1.886298;-1.031365;,
   -0.304643;2.480778;0.452156;,
   0.427739;2.485505;0.301076;,
   -1.494529;1.993816;-0.492156;,
   0.159375;1.724056;-1.858394;,
   0.430761;2.469848;-0.406964;,
   -1.587858;1.975290;0.167902;,
   -0.727342;1.790644;1.648011;,
   0.136352;2.476592;0.546882;,
   0.375105;2.510234;-0.097439;,
   0.265572;1.910794;-1.652199;,
   0.049766;2.498065;-0.456885;,
   -0.580680;2.468530;0.143871;,
   0.626184;2.215825;-1.071982;,
   0.897027;1.917693;-1.403137;,
   -0.500139;2.454189;0.422158;,
   0.245110;2.499304;0.380299;,
   1.187948;2.066991;-0.876176;,
   -0.745325;1.693050;-1.740489;,
   -0.683623;2.432251;-0.261465;,
   0.937026;2.354811;-0.167437;,
   1.464529;2.062417;-0.230226;,
   1.005396;1.849867;1.420731;,
   -0.553240;2.478839;0.023721;,
   -0.155578;2.466747;0.585021;,
   0.013952;2.339464;0.988962;,
   -0.387274;1.940639;1.592278;,
   0.138834;1.985831;1.577472;,
   -0.228209;2.500544;0.383088;,
   0.403243;2.498296;-0.217203;,
   -0.180304;2.418454;-0.755015;,
   -0.799511;2.196754;0.993227;,
   -0.977024;1.921878;1.342827;,
   0.324330;2.470079;-0.495023;,
   -0.422313;2.463181;-0.453784;,
   -1.326393;2.011644;0.803232;,
   0.620136;1.792892;1.688864;,
   0.508124;2.481397;0.188910;,
   -1.133145;1.729949;-1.474684;,
   -0.020076;2.453259;-0.657578;,
   0.669359;1.971104;1.455303;,
   0.152397;2.513335;0.333400;,
   -0.610446;2.464034;-0.084882;,
   0.868269;2.252025;0.791060;,
   1.216165;1.965444;1.053224;,
   0.127282;2.481707;-0.525409;,
   -0.603702;2.438685;-0.373865;,
   1.362128;2.092960;0.464094;,
   -0.284409;1.761963;1.807233;,
   -0.606260;2.443803;0.334409;,
   0.600060;1.789402;-1.699794;,
   -0.312006;2.443414;-0.619516;,
   -0.097981;2.537831;-0.036510;,
   1.134306;-0.800131;2.127067;,
   0.278285;-1.925445;1.632974;,
   0.806254;-1.876611;1.509878;,
   1.590106;0.264566;1.962887;,
   0.338285;-0.422544;2.481631;,
   1.159576;-2.258614;-0.072944;,
   1.029272;-2.165904;0.837029;,
   0.223947;-2.273031;1.111052;,
   1.350424;-1.888391;1.030356;,
   2.003659;-0.328516;1.525999;,
   0.803463;0.246736;2.396826;,
   1.701808;-1.803433;0.550294;,
   2.244039;-0.564479;-1.047334;,
   2.523257;0.183327;0.226040;,
   1.587084;-1.975909;-0.167825;,
   1.284923;-0.649671;2.092417;,
   2.507211;-0.249916;-0.320843;,
   2.311713;0.244102;1.023612;,
   -0.495178;-0.855246;2.339774;,
   -0.265572;-1.912811;1.649872;,
   -1.047334;0.175344;2.307293;,
   -0.895553;-1.919785;1.401275;,
   -0.625407;-2.216909;1.070277;,
   -1.518791;-0.447429;1.985986;,
   -0.176507;0.213637;2.524806;,
   -2.394966;-0.721683;-0.441226;,
   -1.383678;-1.888859;0.984390;,
   -2.387214;0.017597;0.867260;,
   -1.463599;-2.063039;0.230147;,
   -1.008342;-2.324580;0.176119;,
   -0.658894;-0.714243;2.346673;,
   -2.483335;-0.418437;0.330764;,
   -1.982729;0.098989;1.584447;,
   -0.138524;-1.987692;-1.575224;,
   0.387741;-1.942498;-1.589875;,
   -0.023487;-2.310704;-1.054232;,
   0.557271;-0.886331;-2.314116;,
   1.034621;0.181544;-2.312566;,
   -0.304643;-0.518666;-2.467676;,
   0.798271;-2.197994;-0.991443;,
   0.975784;-1.924050;-1.340579;,
   1.548946;-0.396423;-1.973583;,
   0.163327;0.150927;-2.530234;,
   1.510343;-1.824208;-0.917801;,
   2.439927;-0.535178;0.460141;,
   2.380780;0.162166;-0.869897;,
   0.711063;-0.735328;-2.324890;,
   1.972188;0.193406;-1.588788;,
   -0.668663;-1.973042;-1.453055;,
   -1.072137;-0.941367;-2.101332;,
   -1.602898;0.092324;-1.968157;,
   -0.867029;-2.253031;-0.789590;,
   -1.214303;-1.967382;-1.051751;,
   -1.973506;-0.515567;-1.513596;,
   -0.816486;0.117904;-2.402253;,
   -1.579875;-1.918160;-0.525488;,
   -2.199157;-0.692460;1.065627;,
   -2.529614;-0.003721;-0.228597;,
   -1.232830;-0.799897;-2.071566;,
   -2.322099;0.048372;-1.027953;,
   0.103099;-2.537597;0.035814;,
   -0.330921;2.485195;-0.407198;,
   0.432933;2.502792;0.011473;,
   0.006434;2.446360;0.683004;,
   -0.304643;2.480778;0.452156;,
   0.427739;2.485505;0.301076;,
   -1.494529;1.993816;-0.492156;,
   0.159375;1.724056;-1.858394;,
   0.430761;2.469848;-0.406964;,
   -0.727342;1.790644;1.648011;,
   0.136352;2.476592;0.546882;,
   0.375105;2.510234;-0.097439;,
   -0.580680;2.468530;0.143871;,
   0.049766;2.498065;-0.456885;,
   0.245110;2.499304;0.380299;,
   -0.500139;2.454189;0.422158;,
   -0.745325;1.693050;-1.740489;,
   1.187948;2.066991;-0.876176;,
   -0.683623;2.432251;-0.261465;,
   1.005396;1.849867;1.420731;,
   -0.155578;2.466747;0.585021;,
   -0.553240;2.478839;0.023721;,
   -0.180304;2.418454;-0.755015;,
   0.403243;2.498296;-0.217203;,
   -0.228209;2.500544;0.383088;,
   -0.422313;2.463181;-0.453784;,
   0.324330;2.470079;-0.495023;,
   0.620136;1.792892;1.688864;,
   -1.326393;2.011644;0.803232;,
   0.508124;2.481397;0.188910;,
   -1.133145;1.729949;-1.474684;,
   -0.020076;2.453259;-0.657578;,
   0.152397;2.513335;0.333400;,
   -0.610446;2.464034;-0.084882;,
   0.127282;2.481707;-0.525409;,
   -0.603702;2.438685;-0.373865;,
   1.362128;2.092960;0.464094;,
   -0.284409;1.761963;1.807233;,
   -0.606260;2.443803;0.334409;,
   0.600060;1.789402;-1.699794;,
   -0.312006;2.443414;-0.619516;,
   -2.383572;0.826796;0.294178;,
   -2.034667;1.501582;0.238133;,
   -0.909894;1.510884;-1.827774;,
   -1.063999;0.946562;-2.103191;,
   -0.500916;1.039117;2.262876;,
   -0.417507;1.597393;1.930174;,
   2.060712;1.056015;1.043768;,
   1.681655;1.664368;0.923770;,
   1.718861;0.979505;-1.592898;,
   1.389106;1.612354;-1.386393;,
   -0.145113;-1.130199;-2.270008;,
   -1.666771;-1.173917;-1.514915;,
   -2.143112;-1.288954;-0.443863;,
   -1.948312;-1.263604;1.028883;,
   -1.191903;-1.125858;1.939864;,
   0.447739;-0.951677;2.311946;,
   1.594681;-1.044697;1.678320;,
   2.335045;-0.982063;0.185420;,
   2.125284;-1.210351;-0.685173;,
   1.175235;-1.063689;-1.984591;,
   0.131003;-2.535969;0.054882;,
   -0.135654;2.535504;-0.063642;;
   280;
   3;0,1,2;,
   3;1,3,4;,
   3;4,2,1;,
   3;5,6,7;,
   3;0,8,6;,
   3;0,2,8;,
   3;2,9,10;,
   3;10,8,2;,
   3;11,7,6;,
   3;6,8,11;,
   3;11,8,12;,
   3;8,10,13;,
   3;13,12,8;,
   3;11,14,7;,
   3;11,15,14;,
   3;15,16,17;,
   3;17,14,15;,
   3;18,19,1;,
   3;1,19,20;,
   3;20,3,1;,
   3;5,18,1;,
   3;21,22,18;,
   3;18,22,19;,
   3;19,22,23;,
   3;23,24,19;,
   3;25,26,22;,
   3;22,26,27;,
   3;27,23,22;,
   3;28,29,25;,
   3;25,29,30;,
   3;30,29,31;,
   3;31,32,30;,
   3;33,34,35;,
   3;34,36,35;,
   3;35,36,37;,
   3;37,38,35;,
   3;34,33,39;,
   3;39,40,34;,
   3;34,40,36;,
   3;36,40,41;,
   3;41,42,36;,
   3;39,43,40;,
   3;43,44,40;,
   3;40,44,45;,
   3;45,41,40;,
   3;43,14,46;,
   3;46,14,17;,
   3;17,47,46;,
   3;33,35,48;,
   3;48,35,49;,
   3;35,38,50;,
   3;50,49,35;,
   3;33,51,28;,
   3;48,49,52;,
   3;49,53,54;,
   3;54,52,49;,
   3;28,55,29;,
   3;51,52,55;,
   3;55,52,56;,
   3;52,54,57;,
   3;57,56,52;,
   3;55,58,29;,
   3;58,59,31;,
   3;31,29,58;,
   3;33,48,51;,
   3;33,7,39;,
   3;7,43,39;,
   3;5,0,6;,
   3;5,28,21;,
   3;28,25,21;,
   3;25,22,21;,
   3;28,51,55;,
   3;48,52,51;,
   3;7,14,43;,
   3;1,0,5;,
   3;5,21,18;,
   3;7,60,5;,
   3;7,33,60;,
   3;33,28,60;,
   3;60,28,5;,
   3;61,62,63;,
   3;64,65,62;,
   3;62,61,64;,
   3;66,67,68;,
   3;67,69,63;,
   3;69,61,63;,
   3;70,71,61;,
   3;61,69,70;,
   3;67,66,72;,
   3;72,69,67;,
   3;73,69,72;,
   3;74,70,69;,
   3;69,73,74;,
   3;66,75,72;,
   3;75,76,72;,
   3;77,78,76;,
   3;76,75,77;,
   3;62,79,80;,
   3;81,79,62;,
   3;62,65,81;,
   3;62,80,68;,
   3;80,82,83;,
   3;79,82,80;,
   3;84,82,79;,
   3;79,85,84;,
   3;82,86,87;,
   3;88,86,82;,
   3;82,84,88;,
   3;87,89,90;,
   3;91,89,87;,
   3;92,89,91;,
   3;91,93,92;,
   3;94,95,96;,
   3;94,97,95;,
   3;98,97,94;,
   3;94,99,98;,
   3;100,96,95;,
   3;95,101,100;,
   3;97,101,95;,
   3;102,101,97;,
   3;97,103,102;,
   3;101,104,100;,
   3;101,105,104;,
   3;106,105,101;,
   3;101,102,106;,
   3;107,75,104;,
   3;77,75,107;,
   3;107,108,77;,
   3;109,94,96;,
   3;110,94,109;,
   3;111,99,94;,
   3;94,110,111;,
   3;90,112,96;,
   3;113,110,109;,
   3;114,115,110;,
   3;110,113,114;,
   3;89,116,90;,
   3;116,113,112;,
   3;117,113,116;,
   3;118,114,113;,
   3;113,117,118;,
   3;89,119,116;,
   3;92,120,119;,
   3;119,89,92;,
   3;112,109,96;,
   3;100,66,96;,
   3;100,104,66;,
   3;67,63,68;,
   3;83,90,68;,
   3;83,87,90;,
   3;83,82,87;,
   3;116,112,90;,
   3;112,113,109;,
   3;104,75,66;,
   3;63,62,68;,
   3;80,83,68;,
   3;68,121,66;,
   3;121,96,66;,
   3;121,90,96;,
   3;68,90,121;,
   3;64,61,122;,
   3;122,123,64;,
   3;65,64,123;,
   3;123,124,65;,
   3;61,71,125;,
   3;125,122,61;,
   3;71,70,126;,
   3;126,125,71;,
   3;73,72,127;,
   3;127,128,73;,
   3;74,73,128;,
   3;128,129,74;,
   3;70,74,129;,
   3;129,126,70;,
   3;72,76,130;,
   3;130,127,72;,
   3;76,78,131;,
   3;131,130,76;,
   3;78,77,132;,
   3;132,131,78;,
   3;81,65,124;,
   3;124,133,81;,
   3;79,81,133;,
   3;133,134,79;,
   3;84,85,135;,
   3;135,136,84;,
   3;85,79,134;,
   3;134,135,85;,
   3;87,86,137;,
   3;137,138,87;,
   3;88,84,136;,
   3;136,139,88;,
   3;86,88,139;,
   3;139,137,86;,
   3;91,87,138;,
   3;138,140,91;,
   3;92,93,141;,
   3;141,142,92;,
   3;93,91,140;,
   3;140,141,93;,
   3;98,99,143;,
   3;143,144,98;,
   3;97,98,144;,
   3;144,145,97;,
   3;102,103,146;,
   3;146,147,102;,
   3;103,97,145;,
   3;145,146,103;,
   3;104,105,148;,
   3;148,149,104;,
   3;106,102,147;,
   3;147,150,106;,
   3;105,106,150;,
   3;150,148,105;,
   3;107,104,149;,
   3;149,151,107;,
   3;77,108,152;,
   3;152,132,77;,
   3;108,107,151;,
   3;151,152,108;,
   3;111,110,153;,
   3;153,154,111;,
   3;99,111,154;,
   3;154,143,99;,
   3;110,115,155;,
   3;155,153,110;,
   3;115,114,156;,
   3;156,155,115;,
   3;117,116,157;,
   3;157,158,117;,
   3;118,117,158;,
   3;158,159,118;,
   3;114,118,159;,
   3;159,156,114;,
   3;116,119,160;,
   3;160,157,116;,
   3;119,120,161;,
   3;161,160,119;,
   3;120,92,142;,
   3;142,161,120;,
   3;162,163,164;,
   3;164,165,162;,
   3;166,167,163;,
   3;163,162,166;,
   3;168,169,167;,
   3;167,166,168;,
   3;170,171,169;,
   3;169,168,170;,
   3;171,170,164;,
   3;165,172,173;,
   3;174,162,165;,
   3;165,173,174;,
   3;162,174,175;,
   3;176,166,162;,
   3;162,175,176;,
   3;166,176,177;,
   3;178,168,166;,
   3;166,177,178;,
   3;168,178,179;,
   3;180,170,168;,
   3;168,179,180;,
   3;170,180,181;,
   3;172,165,170;,
   3;170,181,172;,
   3;172,182,173;,
   3;173,182,174;,
   3;174,182,175;,
   3;175,182,176;,
   3;176,182,177;,
   3;177,182,178;,
   3;178,182,179;,
   3;179,182,180;,
   3;180,182,181;,
   3;181,182,172;,
   3;163,167,183;,
   3;183,169,171;,
   3;170,165,164;,
   3;183,171,164;,
   3;167,169,183;,
   3;164,163,183;;
  }

  MeshTextureCoords tc0 {
   184;
   0.138500;0.344700;,
   0.131300;0.346300;,
   0.139800;0.347900;,
   0.131300;0.353700;,
   0.135400;0.352000;,
   0.131300;0.336800;,
   0.141300;0.335800;,
   0.143200;0.323900;,
   0.146100;0.340700;,
   0.146300;0.348600;,
   0.151400;0.345900;,
   0.151100;0.333500;,
   0.153600;0.335000;,
   0.154000;0.340800;,
   0.153600;0.323900;,
   0.154900;0.334600;,
   0.159300;0.330700;,
   0.161000;0.323900;,
   0.124000;0.344700;,
   0.122700;0.347900;,
   0.127100;0.352000;,
   0.121200;0.335800;,
   0.116400;0.340700;,
   0.111200;0.345900;,
   0.116200;0.348600;,
   0.111500;0.333500;,
   0.108900;0.335000;,
   0.108500;0.340800;,
   0.118800;0.323900;,
   0.108900;0.323900;,
   0.107700;0.334600;,
   0.101500;0.323900;,
   0.103200;0.330700;,
   0.131300;0.311100;,
   0.138500;0.303200;,
   0.131300;0.301600;,
   0.139800;0.300000;,
   0.135400;0.295900;,
   0.131300;0.294100;,
   0.141300;0.312000;,
   0.146100;0.307200;,
   0.151400;0.301900;,
   0.146300;0.299300;,
   0.151100;0.314400;,
   0.153600;0.312900;,
   0.154000;0.307000;,
   0.154900;0.313300;,
   0.159300;0.317100;,
   0.124000;0.303200;,
   0.122700;0.300000;,
   0.127100;0.295900;,
   0.121200;0.312000;,
   0.116400;0.307200;,
   0.116200;0.299300;,
   0.111200;0.301900;,
   0.111500;0.314400;,
   0.108900;0.312900;,
   0.108500;0.307000;,
   0.107700;0.313300;,
   0.103200;0.317100;,
   0.131300;0.323900;,
   0.139800;0.347800;,
   0.131300;0.346300;,
   0.138500;0.344700;,
   0.135500;0.351800;,
   0.131300;0.353500;,
   0.143200;0.323900;,
   0.141300;0.335800;,
   0.131300;0.336800;,
   0.146100;0.340700;,
   0.151300;0.345800;,
   0.146100;0.348600;,
   0.151100;0.333500;,
   0.153500;0.335000;,
   0.153900;0.340700;,
   0.153500;0.323900;,
   0.154800;0.334500;,
   0.160800;0.323900;,
   0.159200;0.330800;,
   0.122700;0.347800;,
   0.124000;0.344700;,
   0.127000;0.351800;,
   0.116400;0.340700;,
   0.121200;0.335800;,
   0.111300;0.345800;,
   0.116400;0.348600;,
   0.109000;0.335000;,
   0.111400;0.333500;,
   0.108600;0.340700;,
   0.109000;0.323900;,
   0.118800;0.323900;,
   0.107700;0.334500;,
   0.101700;0.323900;,
   0.103300;0.330800;,
   0.131300;0.301600;,
   0.138500;0.303100;,
   0.131300;0.311100;,
   0.139800;0.300000;,
   0.135500;0.296000;,
   0.131300;0.294300;,
   0.141300;0.312000;,
   0.146100;0.307200;,
   0.151300;0.302100;,
   0.146100;0.299300;,
   0.151100;0.314400;,
   0.153500;0.312800;,
   0.153900;0.307200;,
   0.154800;0.313400;,
   0.159200;0.317100;,
   0.124000;0.303100;,
   0.122700;0.300000;,
   0.127000;0.296000;,
   0.121200;0.312000;,
   0.116400;0.307200;,
   0.111300;0.302100;,
   0.116400;0.299300;,
   0.111400;0.314400;,
   0.109000;0.312800;,
   0.108600;0.307200;,
   0.107700;0.313400;,
   0.103300;0.317100;,
   0.131300;0.323900;,
   0.140300;0.349300;,
   0.135600;0.353700;,
   0.131300;0.355500;,
   0.147200;0.350000;,
   0.152600;0.347200;,
   0.153500;0.334500;,
   0.154900;0.335700;,
   0.155400;0.341900;,
   0.156300;0.335200;,
   0.161000;0.331100;,
   0.162800;0.323900;,
   0.126900;0.353700;,
   0.122200;0.349300;,
   0.115300;0.350000;,
   0.110000;0.347200;,
   0.107600;0.335700;,
   0.109500;0.334400;,
   0.107200;0.341900;,
   0.106200;0.335200;,
   0.101600;0.331100;,
   0.099700;0.323900;,
   0.131300;0.292400;,
   0.135600;0.294200;,
   0.140300;0.298600;,
   0.147200;0.297800;,
   0.152600;0.300600;,
   0.154900;0.312200;,
   0.153200;0.313500;,
   0.155400;0.306000;,
   0.156300;0.312700;,
   0.161000;0.316700;,
   0.122200;0.298600;,
   0.126900;0.294200;,
   0.115300;0.297800;,
   0.110000;0.300600;,
   0.109400;0.313400;,
   0.107600;0.312200;,
   0.107200;0.306000;,
   0.106200;0.312700;,
   0.101600;0.316700;,
   0.231700;0.325300;,
   0.234800;0.325300;,
   0.242500;0.316000;,
   0.241600;0.313500;,
   0.241600;0.337000;,
   0.242500;0.334500;,
   0.257500;0.332500;,
   0.255100;0.331000;,
   0.257500;0.318000;,
   0.255100;0.319600;,
   0.246000;0.308800;,
   0.234800;0.311900;,
   0.229600;0.320200;,
   0.229700;0.330400;,
   0.234800;0.338600;,
   0.246000;0.341800;,
   0.257200;0.338600;,
   0.262700;0.330400;,
   0.261800;0.320200;,
   0.257200;0.311900;,
   0.246600;0.325300;,
   0.246000;0.325300;;
  }

  MeshMaterialList mtls {
   1;
   280;
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0;

   Material Dflt_Material {
    0.588000;0.588000;0.588000;1.000000;;
    10.000000;
    0.900000;0.900000;0.900000;;
    0.000000;0.000000;0.000000;;

    TextureFilename Diffuse {
     "Assets/CactusPack_Atlas.png";
    }
   }
  }
 }
}