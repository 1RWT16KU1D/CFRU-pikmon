#ifndef FOLLOWER_MON_SPRITES_H
#define FOLLOWER_MON_SPRITES_H

#include "global.h"
#include "constants/event_objects.h"

#define EVENT_OBJ_PAL_TAG_NONE 0x1102
#define gEventObjectBaseOam_16x16 ((const struct OamData*) 0x83A36F8)
#define gEventObjectBaseOam_16x32 ((const struct OamData*) 0x83A3710)
#define gEventObjectBaseOam_32x32 ((const struct OamData*) 0x83A3718)
#define gEventObjectBaseOam_64x64 ((const struct OamData*) 0x83A3720)
#define gEventObjectSpriteOamTables_16x16 ((const struct SubspriteTable*) 0x83A3748)
#define gEventObjectSpriteOamTables_16x32 ((const struct SubspriteTable*) 0x83A379C)
#define gEventObjectSpriteOamTables_32x32 ((const struct SubspriteTable*) 0x83A37F0)
#define gEventObjectSpriteOamTables_64x64 ((const struct SubspriteTable*) 0x83A38D0)
#define gEventObjectImageAnimTable_PlayerNormal ((const union AnimCmd* const*) 0x83A3470)
#define gEventObjectImageAnimTable_Standard ((const union AnimCmd* const*) 0x83A3368)
#define gEventObjectImageAnimTable_Surfing ((const union AnimCmd* const*) 0x83A3584)
#define gEventObjectImageAnimTable_FieldMove ((const union AnimCmd* const*) 0x83A3638)
#define gEventObjectImageAnimTable_Fishing ((const union AnimCmd* const*) 0x83A3668)
#define gEventObjectImageAnimTable_VsSeekerBike ((const union AnimCmd* const*) 0x83A3640)

#define ANIM_STD_FACE_SOUTH       0
#define ANIM_STD_FACE_NORTH       1
#define ANIM_STD_FACE_WEST        2
#define ANIM_STD_FACE_EAST        3
#define ANIM_STD_GO_SOUTH         4
#define ANIM_STD_GO_NORTH         5
#define ANIM_STD_GO_WEST          6
#define ANIM_STD_GO_EAST          7
#define ANIM_STD_GO_FAST_SOUTH    8
#define ANIM_STD_GO_FAST_NORTH    9
#define ANIM_STD_GO_FAST_WEST     10
#define ANIM_STD_GO_FAST_EAST     11
#define ANIM_STD_GO_FASTER_SOUTH  12
#define ANIM_STD_GO_FASTER_NORTH  13
#define ANIM_STD_GO_FASTER_WEST   14
#define ANIM_STD_GO_FASTER_EAST   15
#define ANIM_STD_GO_FASTEST_SOUTH 16
#define ANIM_STD_GO_FASTEST_NORTH 17
#define ANIM_STD_GO_FASTEST_WEST  18
#define ANIM_STD_GO_FASTEST_EAST  19
#define ANIM_RAISE_HAND           20

#define MON_OW_TEMPLATE_32x32_FRAMES(Id, name)                        \
static const struct SpriteFrameImage sMonPicTable_##name[] =          \
{                                                                     \
    overworld_frame(gFollowingMonPic_##Id##_##name##Tiles, 4, 4, 0),  \
    overworld_frame(gFollowingMonPic_##Id##_##name##Tiles, 4, 4, 1),  \
    overworld_frame(gFollowingMonPic_##Id##_##name##Tiles, 4, 4, 2),  \
    overworld_frame(gFollowingMonPic_##Id##_##name##Tiles, 4, 4, 3),  \
    overworld_frame(gFollowingMonPic_##Id##_##name##Tiles, 4, 4, 4),  \
    overworld_frame(gFollowingMonPic_##Id##_##name##Tiles, 4, 4, 5),  \
    overworld_frame(gFollowingMonPic_##Id##_##name##Tiles, 4, 4, 6),  \
    overworld_frame(gFollowingMonPic_##Id##_##name##Tiles, 4, 4, 7),  \
    overworld_frame(gFollowingMonPic_##Id##_##name##Tiles, 4, 4, 8),  \
};

#define MON_OW_OBJECT_GRAPHICS_32(PalId, name)                 \
{                                                           \
    .tileTag = 0xFFFF,                                      \
    .paletteTag1 = PalId,                                   \
    .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,                  \
    .size = (32 * 32) / 2,                                  \
    .width = 32,                                            \
    .height = 32,                                           \
    .shadowSize = SHADOW_SIZE_M,                            \
    .inanimate = FALSE,                                     \
    .disableReflectionPaletteLoad = FALSE,                  \
    .tracks = TRACKS_FOOT,                                  \
    .gender = MALE,                                         \
    .oam = gEventObjectBaseOam_32x32,                       \
    .subspriteTables = gEventObjectSpriteOamTables_32x32,   \
    .anims = gFollowerMonAnimTable,                         \
    .images = sMonPicTable_##name,                          \
    .affineAnims = gDummySpriteAffineAnimTable,             \
},

#define MON_OW_TEMPLATE_64x64_FRAMES(id, name)                          \
static const struct SpriteFrameImage sMonPicTable_##name[] = {          \
    overworld_frame(gFollowingMonPic_##id##_##name##Tiles, 8, 8, 0),    \
    overworld_frame(gFollowingMonPic_##id##_##name##Tiles, 8, 8, 1),    \
    overworld_frame(gFollowingMonPic_##id##_##name##Tiles, 8, 8, 2),    \
    overworld_frame(gFollowingMonPic_##id##_##name##Tiles, 8, 8, 3),    \
    overworld_frame(gFollowingMonPic_##id##_##name##Tiles, 8, 8, 4),    \
    overworld_frame(gFollowingMonPic_##id##_##name##Tiles, 8, 8, 5),    \
};

#define MON_OW_OBJECT_GRAPHICS_64(PalId, name)                          \
{                                                                       \
        .tileTag = 0xFFFF,                                              \
        .paletteTag1 = PalId,                                           \
        .paletteTag2 = EVENT_OBJ_PAL_TAG_NONE,                          \
        .size = (64 * 64) / 2,                                          \
        .width = 64,                                                    \
        .height = 64,                                                   \
        .shadowSize = SHADOW_SIZE_M,                                    \
        .inanimate = FALSE,                                             \
        .disableReflectionPaletteLoad = FALSE,                          \
        .tracks = TRACKS_FOOT,                                          \
        .gender = MALE,                                                 \
        .oam = gEventObjectBaseOam_64x64,                               \
        .subspriteTables = gEventObjectSpriteOamTables_64x64,           \
        .anims = gFollowerMonAnimTable,                                 \
        .images = sMonPicTable_##name,                                  \
        .affineAnims = gDummySpriteAffineAnimTable,                     \
},

extern const u16 gFollowerMonSpriteIdTable[];
extern const union AnimCmd *const gFollowerMonAnimTable[];

// Overworld Tables
extern const struct EventObjectGraphicsInfo gFollowerMonGfxTable0[];

// Tiles
extern const u8 gFollowingMonPic_0001_BulborbLarvaTiles[];
extern const u8 gFollowingMonPic_0002_BulborbTiles[];
extern const u8 gFollowingMonPic_0003_JumboBulborbTiles[];
extern const u8 gFollowingMonPic_0004_FieryBlowletTiles[];
extern const u8 gFollowingMonPic_0005_FieryBlowhogTiles[];
extern const u8 gFollowingMonPic_0006_TitanBlowhogTiles[];
extern const u8 gFollowingMonPic_0007_WolpoleTiles[];
extern const u8 gFollowingMonPic_0008_YellowWollyhopTiles[];
extern const u8 gFollowingMonPic_0009_MasterhopTiles[];
extern const u8 gFollowingMonPic_0010_FlintBeetleTiles[];
extern const u8 gFollowingMonPic_0011_DoodlebugTiles[];
extern const u8 gFollowingMonPic_0012_GlintBeetleTiles[];
extern const u8 gFollowingMonPic_0013_SwoopingSnitchbugTiles[];
extern const u8 gFollowingMonPic_0014_BumblingSnitchbugTiles[];
extern const u8 gFollowingMonPic_0015_DirigibugTiles[];
extern const u8 gFollowingMonPic_0016_SnowBulborbTiles[];
extern const u8 gFollowingMonPic_0017_DwarfFrostyBulborbTiles[];
extern const u8 gFollowingMonPic_0018_FrostyBulborbTiles[];
extern const u8 gFollowingMonPic_0019_CrumbugTiles[];
extern const u8 gFollowingMonPic_0020_BreadbugTiles[];
extern const u8 gFollowingMonPic_0021_GiantBreadbugTiles[];
extern const u8 gFollowingMonPic_0022_EmperorBulblaxTiles[];
extern const u8 gFollowingMonPic_0023_SovreignBulblaxTiles[];
extern const u8 gFollowingMonPic_0024_DwarfBulbearTiles[];
extern const u8 gFollowingMonPic_0025_BulbearTiles[];
extern const u8 gFollowingMonPic_0026_HoneywispTiles[];
extern const u8 gFollowingMonPic_0027_DandelflyTiles[];
extern const u8 gFollowingMonPic_0028_DownySnagretTiles[];
extern const u8 gFollowingMonPic_0029_BurrowingSnagretTiles[];
extern const u8 gFollowingMonPic_0030_PileatedSnagretTiles[];
extern const u8 gFollowingMonPic_0031_FemaleSheargrubTiles[];
extern const u8 gFollowingMonPic_0032_SwarmingSheargrubTiles[];
extern const u8 gFollowingMonPic_0033_MamaSheargrubTiles[];
extern const u8 gFollowingMonPic_0034_MaleSheargrubTiles[];
extern const u8 gFollowingMonPic_0035_ShearwigTiles[];
extern const u8 gFollowingMonPic_0036_QueenShearwigTiles[];
extern const u8 gFollowingMonPic_0037_AristocrabOffspringTiles[];
extern const u8 gFollowingMonPic_0038_PeckishAristocrabTiles[];
extern const u8 gFollowingMonPic_0039_GoolixTiles[];
extern const u8 gFollowingMonPic_0040_FoolixTiles[];
extern const u8 gFollowingMonPic_0041_ArcticCannonLarvaTiles[];
extern const u8 gFollowingMonPic_0042_ArcticCannonBeetleTiles[];
extern const u8 gFollowingMonPic_0043_SkitterleafTiles[];
extern const u8 gFollowingMonPic_0044_DesiccatedSkitterleafTiles[];
extern const u8 gFollowingMonPic_0045_ArmoredCannonLarvaTiles[];
extern const u8 gFollowingMonPic_0046_ArmoredCannonBeetleTiles[];
extern const u8 gFollowingMonPic_0047_HornedCannonBeetleTiles[];
extern const u8 gFollowingMonPic_0048_CreepingChrysanthemumTiles[];
extern const u8 gFollowingMonPic_0049_StartleSporeTiles[];
extern const u8 gFollowingMonPic_0050_HermitCrawmadTiles[];
extern const u8 gFollowingMonPic_0051_BugEyedCrawmadTiles[];
extern const u8 gFollowingMonPic_0052_DwarfBulborbTiles[];
extern const u8 gFollowingMonPic_0053_DwarfOrangeBulborbTiles[];
extern const u8 gFollowingMonPic_0054_BeadyLonLegsTiles[];
extern const u8 gFollowingMonPic_0055_RagingLongLegsTiles[];
extern const u8 gFollowingMonPic_0056_BaldyLongLegsTiles[];
extern const u8 gFollowingMonPic_0057_ShaggyLongLegsTiles[];
extern const u8 gFollowingMonPic_0058_BulbminTiles[];
extern const u8 gFollowingMonPic_0059_AdultBulbminTiles[];
extern const u8 gFollowingMonPic_0060_ScornetTiles[];
extern const u8 gFollowingMonPic_0061_ScornetMaestroTiles[];
extern const u8 gFollowingMonPic_0062_BurrowNitTiles[];
extern const u8 gFollowingMonPic_0063_JoustmiteTiles[];
extern const u8 gFollowingMonPic_0064_FlightyJoustmiteTiles[];
extern const u8 gFollowingMonPic_0065_VolatileDweevilTiles[];
extern const u8 gFollowingMonPic_0066_ManAtLegsTiles[];
extern const u8 gFollowingMonPic_0067_SkutterchuckTiles[];
extern const u8 gFollowingMonPic_0068_CalcifiedCrushblatTiles[];
extern const u8 gFollowingMonPic_0069_ArachnodeTiles[];
extern const u8 gFollowingMonPic_0070_MoldyDwarfBulborbTiles[];
extern const u8 gFollowingMonPic_0071_MoldySloochTiles[];
extern const u8 gFollowingMonPic_0072_ToxstoolTiles[];
extern const u8 gFollowingMonPic_0073_PhosbatTiles[];
extern const u8 gFollowingMonPic_0074_VeheamothPhosbatTiles[];
extern const u8 gFollowingMonPic_0075_PuckeringBlinnowTiles[];
extern const u8 gFollowingMonPic_0076_SputtlefishTiles[];
extern const u8 gFollowingMonPic_0077_PricklepuffTiles[];
extern const u8 gFollowingMonPic_0078_UjadaniTiles[];
extern const u8 gFollowingMonPic_0079_MititeTiles[];
extern const u8 gFollowingMonPic_0080_WitheringBlowhogTiles[];
extern const u8 gFollowingMonPic_0081_PuffyBlowhogTiles[];
extern const u8 gFollowingMonPic_0082_MiniatureSnootwhackerTiles[];
extern const u8 gFollowingMonPic_0083_MammothSnootwhackerTiles[];
extern const u8 gFollowingMonPic_0084_PyroclasticSloochTiles[];
extern const u8 gFollowingMonPic_0085_LesserSpottedJellyfloatTiles[];
extern const u8 gFollowingMonPic_0086_GreaterSpottedJellyfloatTiles[];
extern const u8 gFollowingMonPic_0087_ToadyBloysterTiles[];
extern const u8 gFollowingMonPic_0088_RangingBloysterTiles[];
extern const u8 gFollowingMonPic_0089_SnowyBlowhogTiles[];
extern const u8 gFollowingMonPic_0090_BlizzardingBlowhogTiles[];
extern const u8 gFollowingMonPic_0091_GildemandweeTiles[];
extern const u8 gFollowingMonPic_0092_GildemanderTiles[];
extern const u8 gFollowingMonPic_0093_WaddlequaffTiles[];
extern const u8 gFollowingMonPic_0094_GrubchuckerTiles[];
extern const u8 gFollowingMonPic_0095_PearlyClamclampTiles[];
extern const u8 gFollowingMonPic_0096_SunsquishTiles[];
extern const u8 gFollowingMonPic_0097_PorquillionTiles[];
extern const u8 gFollowingMonPic_0098_TuskedBlowhogTiles[];
extern const u8 gFollowingMonPic_0099_SnowflakeFluttertailTiles[];
extern const u8 gFollowingMonPic_0100_BogswallowTiles[];
extern const u8 gFollowingMonPic_0101_PuffminTiles[];
extern const u8 gFollowingMonPic_0102_WollyhopTiles[];
extern const u8 gFollowingMonPic_0103_ChillyhopTiles[];
extern const u8 gFollowingMonPic_0104_BloomcapBloysterTiles[];
extern const u8 gFollowingMonPic_0105_ScorchcakeTiles[];
extern const u8 gFollowingMonPic_0106_WaterDumpleTiles[];
extern const u8 gFollowingMonPic_0107_LongWaterDumpleTiles[];
extern const u8 gFollowingMonPic_0108_MockiwiTiles[];
extern const u8 gFollowingMonPic_0109_CrestedMockiwiTiles[];
extern const u8 gFollowingMonPic_0110_ElongatedCrushblatTiles[];
extern const u8 gFollowingMonPic_0111_PuffstalkTiles[];
extern const u8 gFollowingMonPic_0112_PuffstoolTiles[];
extern const u8 gFollowingMonPic_0113_AnodeBeetleTiles[];
extern const u8 gFollowingMonPic_0114_EmpressBulblaxTiles[];
extern const u8 gFollowingMonPic_0115_SkeeterskateTiles[];
extern const u8 gFollowingMonPic_0116_MuckerskateTiles[];
extern const u8 gFollowingMonPic_0117_GroovyLongLegsTiles[];
extern const u8 gFollowingMonPic_0118_CrustedRumpupTiles[];
extern const u8 gFollowingMonPic_0119_BeardedAmpratTiles[];
extern const u8 gFollowingMonPic_0120_FieryBulblaxTiles[];
extern const u8 gFollowingMonPic_0121_GattlingGroinkTiles[];
extern const u8 gFollowingMonPic_0122_ArmurkTiles[];
extern const u8 gFollowingMonPic_0123_SegmentedCrawbsterTiles[];
extern const u8 gFollowingMonPic_0124_ArmoredMawdadTiles[];
extern const u8 gFollowingMonPic_0125_SandbelchingMeerslugTiles[];
extern const u8 gFollowingMonPic_0126_ClickingSlurkerTiles[];
extern const u8 gFollowingMonPic_0127_LuringSlurkerTiles[];
extern const u8 gFollowingMonPic_0128_MedusalSlurkerTiles[];
extern const u8 gFollowingMonPic_0129_PelletPosyTiles[];
extern const u8 gFollowingMonPic_0130_MasterOnionTiles[];
extern const u8 gFollowingMonPic_0131_OatchiTiles[];
extern const u8 gFollowingMonPic_0132_QuaggledMireclopsTiles[];
extern const u8 gFollowingMonPic_0133_AlbinoDwarfBulborbTiles[];
extern const u8 gFollowingMonPic_0134_HairyBulborbTiles[];
extern const u8 gFollowingMonPic_0135_WhiptongueBulborbTiles[];
extern const u8 gFollowingMonPic_0136_OrangeBulborbTiles[];
extern const u8 gFollowingMonPic_0137_WhitePikminTiles[];
extern const u8 gFollowingMonPic_0138_BluePikminTiles[];
extern const u8 gFollowingMonPic_0139_RockPikminTiles[];
extern const u8 gFollowingMonPic_0140_YellowPikminTiles[];
extern const u8 gFollowingMonPic_0141_WingedPikminTiles[];
extern const u8 gFollowingMonPic_0142_RedPikminTiles[];
extern const u8 gFollowingMonPic_0143_PurplePikminTiles[];
extern const u8 gFollowingMonPic_0144_WaterWraithTiles[];
extern const u8 gFollowingMonPic_0145_TitanDweevilTiles[];
extern const u8 gFollowingMonPic_0146_PlasmWraithTiles[];
extern const u8 gFollowingMonPic_0147_IcePikminTiles[];
extern const u8 gFollowingMonPic_0148_GlowSeedTiles[];
extern const u8 gFollowingMonPic_0149_GlowPikminTiles[];
extern const u8 gFollowingMonPic_0150_SmokyProggTiles[];
extern const u8 gFollowingMonPic_0151_MamutaTiles[];
extern const u8 gFollowingMonPic_0152_MossTiles[];
extern const u8 gFollowingMonPic_0153_ToyBorbTiles[];
extern const u8 gFollowingMonPic_0154_BulblordTiles[];
extern const u8 gFollowingMonPic_0155_PinchipedeTiles[];
extern const u8 gFollowingMonPic_0156_LargeMothWollyhopTiles[];
extern const u8 gFollowingMonPic_0157_ToyBlowhogTiles[];
extern const u8 gFollowingMonPic_0158_TelescopingPumphogTiles[];
extern const u8 gFollowingMonPic_0159_BeebTiles[];
extern const u8 gFollowingMonPic_0160_BladedBeebTiles[];
extern const u8 gFollowingMonPic_0161_StuddedBeebTiles[];
extern const u8 gFollowingMonPic_0162_FireflapBulborbTiles[];
extern const u8 gFollowingMonPic_0163_IceblownDweevilTiles[];
extern const u8 gFollowingMonPic_0164_SpectralidTiles[];
extern const u8 gFollowingMonPic_0165_BlubbugTiles[];
extern const u8 gFollowingMonPic_0166_PuffyBlubbugTiles[];
extern const u8 gFollowingMonPic_0167_StuffedBellbloomTiles[];
extern const u8 gFollowingMonPic_0168_CentipareTiles[];
extern const u8 gFollowingMonPic_0169_AdultCentipareTiles[];
extern const u8 gFollowingMonPic_0170_WateryBlowhogTiles[];
extern const u8 gFollowingMonPic_0171_GrabbitTiles[];
extern const u8 gFollowingMonPic_0172_CoppellerTiles[];
extern const u8 gFollowingMonPic_0173_MuggonflyTiles[];
extern const u8 gFollowingMonPic_0174_ElectricCottonadeTiles[];
extern const u8 gFollowingMonPic_0175_WaddlepusTiles[];
extern const u8 gFollowingMonPic_0176_CrammedWraithTiles[];
extern const u8 gFollowingMonPic_0177_BerserkLeechHydroeTiles[];
extern const u8 gFollowingMonPic_0178_PebblePitcherTiles[];
extern const u8 gFollowingMonPic_0189_AncientSirehoundTiles[];
extern const u8 gFollowingMonPic_0180_CourageReactorTiles[];
extern const u8 gFollowingMonPic_0181_AssembledCourageTiles[];
extern const u8 gFollowingMonPic_0182_RememberedOldBuddyTiles[];
extern const u8 gFollowingMonPic_0183_BulborbWithAGunTiles[];
extern const u8 gFollowingMonPic_0184_KirbyTiles[];
extern const u8 gFollowingMonPic_0185_SoulTiles[];
extern const u8 gFollowingMonPic_0000_PlaceholderLarvaTiles[];
extern const u8 gFollowingMonPic_0186_Demo77Tiles[];
extern const u8 gFollowingMonPic_0187_UsubaTiles[];
extern const u8 gFollowingMonPic_0188_KakureimoTiles[];
extern const u8 gFollowingMonPic_0189_PikutabeTiles[];
extern const u8 gFollowingMonPic_0190_NamaPongashiTiles[];
extern const u8 gFollowingMonPic_0191_ChappyProtoTiles[];
extern const u8 gFollowingMonPic_0412_EggTiles[];
extern const u8 gFollowingMonPic_0192_RedBubblimpTiles[];
extern const u8 gFollowingMonPic_0193_StarnacleTiles[];
extern const u8 gFollowingMonPic_0194_ShearfleaTiles[];
extern const u8 gFollowingMonPic_0195_WhiskerPillarTiles[];
extern const u8 gFollowingMonPic_0196_IcyBlowhogTiles[];
extern const u8 gFollowingMonPic_0212_FreezecakeTiles[];
extern const u8 gFollowingMonPic_0213_ShockcakeTiles[];
extern const u8 gFollowingMonPic_0214_WideMouthedAnodeBeetleTiles[];
extern const u8 gFollowingMonPic_0215_DecoratedCannonBeetleTiles[];
extern const u8 gFollowingMonPic_0208_AntennaBeetleTiles[];
extern const u8 gFollowingMonPic_0142_RedPikminVeteranTiles[];
extern const u8 gFollowingMonPic_0145_TitanDweevilElectricTiles[];
extern const u8 gFollowingMonPic_0145_TitanDweevilFireTiles[];
extern const u8 gFollowingMonPic_0145_TitanDweevilPoisonTiles[];
extern const u8 gFollowingMonPic_0145_TitanDweevilWaterTiles[];
extern const u8 gFollowingMonPic_0165_SpectralidRedTiles[];
extern const u8 gFollowingMonPic_0165_SpectralidYellowTiles[];
extern const u8 gFollowingMonPic_0165_SpectralidUnmarkedTiles[];
extern const u8 gFollowingMonPic_0165_SpectralidUnmarkedRedTiles[];
extern const u8 gFollowingMonPic_0165_SpectralidUnmarkedPurpleTiles[];
extern const u8 gFollowingMonPic_0165_SpectralidElectricTiles[];
extern const u8 gFollowingMonPic_0165_SpectralidHey0Tiles[];
extern const u8 gFollowingMonPic_0165_SpectralidHey1Tiles[];
extern const u8 gFollowingMonPic_0179_AncientSirehoundIceTiles[];
extern const u8 gFollowingMonPic_0179_AncientSirehoundElectricTiles[];
extern const u8 gFollowingMonPic_0179_AncientSirehoundFireTiles[];
extern const u8 gFollowingMonPic_0179_AncientSirehoundGloomTiles[];
extern const u8 gFollowingMonPic_0184_KirbyFlyingTiles[];
extern const u8 gFollowingMonPic_0184_KirbyGrassTiles[];
extern const u8 gFollowingMonPic_0184_KirbyBugTiles[];
extern const u8 gFollowingMonPic_0184_KirbyPoisonTiles[];
extern const u8 gFollowingMonPic_0184_KirbyWaterTiles[];
extern const u8 gFollowingMonPic_0184_KirbyIceTiles[];
extern const u8 gFollowingMonPic_0184_KirbyFireTiles[];
extern const u8 gFollowingMonPic_0184_KirbyElectricTiles[];
extern const u8 gFollowingMonPic_0184_KirbyFightingTiles[];
extern const u8 gFollowingMonPic_0184_KirbyRockTiles[];
extern const u8 gFollowingMonPic_0184_KirbyGroundTiles[];
extern const u8 gFollowingMonPic_0184_KirbyPsychicTiles[];
extern const u8 gFollowingMonPic_0184_KirbyGhostTiles[];
extern const u8 gFollowingMonPic_0184_KirbyDragonTiles[];
extern const u8 gFollowingMonPic_0184_KirbyDarkTiles[];
extern const u8 gFollowingMonPic_0184_KirbySteelTiles[];
extern const u8 gFollowingMonPic_0184_KirbyFairyTiles[];
extern const u8 gFollowingMonPic_0185_SoulRedTiles[];
extern const u8 gFollowingMonPic_0185_SoulYellowTiles[];
extern const u8 gFollowingMonPic_0185_SoulBlueTiles[];
extern const u8 gFollowingMonPic_0185_SoulPurpleTiles[];
extern const u8 gFollowingMonPic_0185_SoulWhiteTiles[];
extern const u8 gFollowingMonPic_0185_SoulRockTiles[];
extern const u8 gFollowingMonPic_0185_SoulWingedTiles[];
extern const u8 gFollowingMonPic_0185_SoulIceTiles[];
extern const u8 gFollowingMonPic_0164_IceblownDweevilFireTiles[];
extern const u8 gFollowingMonPic_0164_IceblownDweevilElectricTiles[];
extern const u8 gFollowingMonPic_0164_IceblownDweevilWaterTiles[];
extern const u8 gFollowingMonPic_0164_IceblownDweevilPoisonTiles[];
extern const u8 gFollowingMonPic_0197_MysteriousLifeFormTiles[];
extern const u8 gFollowingMonPic_0197_MysteriousLifeFormBulborbTiles[];
extern const u8 gFollowingMonPic_0197_MysteriousLifeFormAmpratTiles[];
extern const u8 gFollowingMonPic_0197_MysteriousLifeFormDandelflyTiles[];
extern const u8 gFollowingMonPic_0197_MysteriousLifeFormArachnodeTiles[];
extern const u8 gFollowingMonPic_0197_MysteriousLifeFormBlowhogTiles[];
extern const u8 gFollowingMonPic_0198_PeteyPirannhaTiles[];
extern const u8 gFollowingMonPic_0199_ToyPikminRedTiles[];
extern const u8 gFollowingMonPic_0199_ToyPikminYellowTiles[];
extern const u8 gFollowingMonPic_0199_ToyPikminBlueTiles[];
extern const u8 gFollowingMonPic_0200_PikiMaleTiles[];
extern const u8 gFollowingMonPic_0200_PikiFemaleTiles[];
extern const u8 gFollowingMonPic_0201_DemoFTiles[];
extern const u8 gFollowingMonPic_0202_DemoGTiles[];
extern const u8 gFollowingMonPic_0203_DemoITiles[];
extern const u8 gFollowingMonPic_0204_DemoWTiles[];
extern const u8 gFollowingMonPic_0205_UsualSuspectTiles[];
extern const u8 gFollowingMonPic_0206_MeteorTiles[];
extern const u8 gFollowingMonPic_0207_CherryTiles[];
extern const u8 gFollowingMonPic_0209_FieryYoungYellowWollyhopTiles[];
extern const u8 gFollowingMonPic_0210_HotelTransylvaniaTiles[];
extern const u8 gFollowingMonPic_0211_CalyrexTiles[];
extern const u8 gFollowingMonPic_0216_SkeleminTiles[];
extern const u8 gFollowingMonPic_0217_MoyaiminTiles[];
extern const u8 gFollowingMonPic_0218_CockatriceTiles[];
extern const u8 gFollowingMonPic_0219_BupborbTiles[];
extern const u8 gFollowingMonPic_0220_DwarfKermitTiles[];
extern const u8 gFollowingMonPic_0221_BulblaxLarvaTiles[];
extern const u8 gFollowingMonPic_0222_CoalBeetleTiles[];
extern const u8 gFollowingMonPic_0223_HeavyCannonLarvaTiles[];
extern const u8 gFollowingMonPic_0224_CrewmateTiles[];
extern const u8 gFollowingMonPic_0225_ImposterTiles[];
extern const u8 gFollowingMonPic_0226_ApacheTiles[];
extern const u8 gFollowingMonPic_0227_MorshubugTiles[];
extern const u8 gFollowingMonPic_0228_SkitterjuanaTiles[];
extern const u8 gFollowingMonPic_0229_WahpoleTiles[];
extern const u8 gFollowingMonPic_0230_WaluigiwogTiles[];
extern const u8 gFollowingMonPic_0231_StephanTiles[];
extern const u8 gFollowingMonPic_0232_LinkgretTiles[];
extern const u8 gFollowingMonPic_0233_OliManAtLegsTiles[];
extern const u8 gFollowingMonPic_0234_BulbeelTiles[];
extern const u8 gFollowingMonPic_0235_IwagenTiles[];
extern const u8 gFollowingMonPic_0236_128MariosTiles[];
extern const u8 gFollowingMonPic_0237_FiddleheadTiles[];
extern const u8 gFollowingMonPic_0238_HorsetailTiles[];
extern const u8 gFollowingMonPic_0239_SpotcapTiles[];
extern const u8 gFollowingMonPic_0240_KingcapTiles[];
extern const u8 gFollowingMonPic_0241_BulbieTiles[];
extern const u8 gFollowingMonPic_0242_SlugcatTiles[];
extern const u8 gFollowingMonPic_0243_PinkElebitTiles[];
extern const u8 gFollowingMonPic_0244_PrimalAspidTiles[];
extern const u8 gFollowingMonPic_0245_ChibiRoboTiles[];
extern const u8 gFollowingMonPic_0246_PikachuTiles[];
extern const u8 gFollowingMonPic_0150_SmokyProgMasterTiles[];
// Tiles
extern const u8 gShinyFollowingMonPic_0001_BulborbLarvaTiles[];
extern const u8 gShinyFollowingMonPic_0002_BulborbTiles[];
extern const u8 gShinyFollowingMonPic_0003_JumboBulborbTiles[];
extern const u8 gShinyFollowingMonPic_0004_FieryBlowletTiles[];
extern const u8 gShinyFollowingMonPic_0005_FieryBlowhogTiles[];
extern const u8 gShinyFollowingMonPic_0006_TitanBlowhogTiles[];
extern const u8 gShinyFollowingMonPic_0007_WolpoleTiles[];
extern const u8 gShinyFollowingMonPic_0008_YellowWollyhopTiles[];
extern const u8 gShinyFollowingMonPic_0009_MasterhopTiles[];
extern const u8 gShinyFollowingMonPic_0010_FlintBeetleTiles[];
extern const u8 gShinyFollowingMonPic_0011_DoodlebugTiles[];
extern const u8 gShinyFollowingMonPic_0012_GlintBeetleTiles[];
extern const u8 gShinyFollowingMonPic_0013_SwoopingSnitchbugTiles[];
extern const u8 gShinyFollowingMonPic_0014_BumblingSnitchbugTiles[];
extern const u8 gShinyFollowingMonPic_0015_DirigibugTiles[];
extern const u8 gShinyFollowingMonPic_0016_SnowBulborbTiles[];
extern const u8 gShinyFollowingMonPic_0017_DwarfFrostyBulborbTiles[];
extern const u8 gShinyFollowingMonPic_0018_FrostyBulborbTiles[];
extern const u8 gShinyFollowingMonPic_0019_CrumbugTiles[];
extern const u8 gShinyFollowingMonPic_0020_BreadbugTiles[];
extern const u8 gShinyFollowingMonPic_0021_GiantBreadbugTiles[];
extern const u8 gShinyFollowingMonPic_0022_EmperorBulblaxTiles[];
extern const u8 gShinyFollowingMonPic_0023_SovreignBulblaxTiles[];
extern const u8 gShinyFollowingMonPic_0024_DwarfBulbearTiles[];
extern const u8 gShinyFollowingMonPic_0025_BulbearTiles[];
extern const u8 gShinyFollowingMonPic_0026_HoneywispTiles[];
extern const u8 gShinyFollowingMonPic_0027_DandelflyTiles[];
extern const u8 gShinyFollowingMonPic_0028_DownySnagretTiles[];
extern const u8 gShinyFollowingMonPic_0029_BurrowingSnagretTiles[];
extern const u8 gShinyFollowingMonPic_0030_PileatedSnagretTiles[];
extern const u8 gShinyFollowingMonPic_0031_FemaleSheargrubTiles[];
extern const u8 gShinyFollowingMonPic_0032_SwarmingSheargrubTiles[];
extern const u8 gShinyFollowingMonPic_0033_MamaSheargrubTiles[];
extern const u8 gShinyFollowingMonPic_0034_MaleSheargrubTiles[];
extern const u8 gShinyFollowingMonPic_0035_ShearwigTiles[];
extern const u8 gShinyFollowingMonPic_0036_QueenShearwigTiles[];
extern const u8 gShinyFollowingMonPic_0037_AristocrabOffspringTiles[];
extern const u8 gShinyFollowingMonPic_0038_PeckishAristocrabTiles[];
extern const u8 gShinyFollowingMonPic_0039_GoolixTiles[];
extern const u8 gShinyFollowingMonPic_0040_FoolixTiles[];
extern const u8 gShinyFollowingMonPic_0041_ArcticCannonLarvaTiles[];
extern const u8 gShinyFollowingMonPic_0042_ArcticCannonBeetleTiles[];
extern const u8 gShinyFollowingMonPic_0043_SkitterleafTiles[];
extern const u8 gShinyFollowingMonPic_0044_DesiccatedSkitterleafTiles[];
extern const u8 gShinyFollowingMonPic_0045_ArmoredCannonLarvaTiles[];
extern const u8 gShinyFollowingMonPic_0046_ArmoredCannonBeetleTiles[];
extern const u8 gShinyFollowingMonPic_0047_HornedCannonBeetleTiles[];
extern const u8 gShinyFollowingMonPic_0048_CreepingChrysanthemumTiles[];
extern const u8 gShinyFollowingMonPic_0049_StartleSporeTiles[];
extern const u8 gShinyFollowingMonPic_0050_HermitCrawmadTiles[];
extern const u8 gShinyFollowingMonPic_0051_BugEyedCrawmadTiles[];
extern const u8 gShinyFollowingMonPic_0052_DwarfBulborbTiles[];
extern const u8 gShinyFollowingMonPic_0053_DwarfOrangeBulborbTiles[];
extern const u8 gShinyFollowingMonPic_0054_BeadyLonLegsTiles[];
extern const u8 gShinyFollowingMonPic_0055_RagingLongLegsTiles[];
extern const u8 gShinyFollowingMonPic_0056_BaldyLongLegsTiles[];
extern const u8 gShinyFollowingMonPic_0057_ShaggyLongLegsTiles[];
extern const u8 gShinyFollowingMonPic_0058_BulbminTiles[];
extern const u8 gShinyFollowingMonPic_0059_AdultBulbminTiles[];
extern const u8 gShinyFollowingMonPic_0060_ScornetTiles[];
extern const u8 gShinyFollowingMonPic_0061_ScornetMaestroTiles[];
extern const u8 gShinyFollowingMonPic_0062_BurrowNitTiles[];
extern const u8 gShinyFollowingMonPic_0063_JoustmiteTiles[];
extern const u8 gShinyFollowingMonPic_0064_FlightyJoustmiteTiles[];
extern const u8 gShinyFollowingMonPic_0065_VolatileDweevilTiles[];
extern const u8 gShinyFollowingMonPic_0066_ManAtLegsTiles[];
extern const u8 gShinyFollowingMonPic_0067_SkutterchuckTiles[];
extern const u8 gShinyFollowingMonPic_0068_CalcifiedCrushblatTiles[];
extern const u8 gShinyFollowingMonPic_0069_ArachnodeTiles[];
extern const u8 gShinyFollowingMonPic_0070_MoldyDwarfBulborbTiles[];
extern const u8 gShinyFollowingMonPic_0071_MoldySloochTiles[];
extern const u8 gShinyFollowingMonPic_0072_ToxstoolTiles[];
extern const u8 gShinyFollowingMonPic_0073_PhosbatTiles[];
extern const u8 gShinyFollowingMonPic_0074_VeheamothPhosbatTiles[];
extern const u8 gShinyFollowingMonPic_0075_PuckeringBlinnowTiles[];
extern const u8 gShinyFollowingMonPic_0076_SputtlefishTiles[];
extern const u8 gShinyFollowingMonPic_0077_PricklepuffTiles[];
extern const u8 gShinyFollowingMonPic_0078_UjadaniTiles[];
extern const u8 gShinyFollowingMonPic_0079_MititeTiles[];
extern const u8 gShinyFollowingMonPic_0080_WitheringBlowhogTiles[];
extern const u8 gShinyFollowingMonPic_0081_PuffyBlowhogTiles[];
extern const u8 gShinyFollowingMonPic_0082_MiniatureSnootwhackerTiles[];
extern const u8 gShinyFollowingMonPic_0083_MammothSnootwhackerTiles[];
extern const u8 gShinyFollowingMonPic_0084_PyroclasticSloochTiles[];
extern const u8 gShinyFollowingMonPic_0085_LesserSpottedJellyfloatTiles[];
extern const u8 gShinyFollowingMonPic_0086_GreaterSpottedJellyfloatTiles[];
extern const u8 gShinyFollowingMonPic_0087_ToadyBloysterTiles[];
extern const u8 gShinyFollowingMonPic_0088_RangingBloysterTiles[];
extern const u8 gShinyFollowingMonPic_0089_SnowyBlowhogTiles[];
extern const u8 gShinyFollowingMonPic_0090_BlizzardingBlowhogTiles[];
extern const u8 gShinyFollowingMonPic_0091_GildemandweeTiles[];
extern const u8 gShinyFollowingMonPic_0092_GildemanderTiles[];
extern const u8 gShinyFollowingMonPic_0093_WaddlequaffTiles[];
extern const u8 gShinyFollowingMonPic_0094_GrubchuckerTiles[];
extern const u8 gShinyFollowingMonPic_0095_PearlyClamclampTiles[];
extern const u8 gShinyFollowingMonPic_0096_SunsquishTiles[];
extern const u8 gShinyFollowingMonPic_0097_PorquillionTiles[];
extern const u8 gShinyFollowingMonPic_0098_TuskedBlowhogTiles[];
extern const u8 gShinyFollowingMonPic_0099_SnowflakeFluttertailTiles[];
extern const u8 gShinyFollowingMonPic_0100_BogswallowTiles[];
extern const u8 gShinyFollowingMonPic_0101_PuffminTiles[];
extern const u8 gShinyFollowingMonPic_0102_WollyhopTiles[];
extern const u8 gShinyFollowingMonPic_0103_ChillyhopTiles[];
extern const u8 gShinyFollowingMonPic_0104_BloomcapBloysterTiles[];
extern const u8 gShinyFollowingMonPic_0105_ScorchcakeTiles[];
extern const u8 gShinyFollowingMonPic_0106_WaterDumpleTiles[];
extern const u8 gShinyFollowingMonPic_0107_LongWaterDumpleTiles[];
extern const u8 gShinyFollowingMonPic_0108_MockiwiTiles[];
extern const u8 gShinyFollowingMonPic_0109_CrestedMockiwiTiles[];
extern const u8 gShinyFollowingMonPic_0110_ElongatedCrushblatTiles[];
extern const u8 gShinyFollowingMonPic_0111_PuffstalkTiles[];
extern const u8 gShinyFollowingMonPic_0112_PuffstoolTiles[];
extern const u8 gShinyFollowingMonPic_0113_AnodeBeetleTiles[];
extern const u8 gShinyFollowingMonPic_0114_EmpressBulblaxTiles[];
extern const u8 gShinyFollowingMonPic_0115_SkeeterskateTiles[];
extern const u8 gShinyFollowingMonPic_0116_MuckerskateTiles[];
extern const u8 gShinyFollowingMonPic_0117_GroovyLongLegsTiles[];
extern const u8 gShinyFollowingMonPic_0118_CrustedRumpupTiles[];
extern const u8 gShinyFollowingMonPic_0119_BeardedAmpratTiles[];
extern const u8 gShinyFollowingMonPic_0120_FieryBulblaxTiles[];
extern const u8 gShinyFollowingMonPic_0121_GattlingGroinkTiles[];
extern const u8 gShinyFollowingMonPic_0122_ArmurkTiles[];
extern const u8 gShinyFollowingMonPic_0123_SegmentedCrawbsterTiles[];
extern const u8 gShinyFollowingMonPic_0124_ArmoredMawdadTiles[];
extern const u8 gShinyFollowingMonPic_0125_SandbelchingMeerslugTiles[];
extern const u8 gShinyFollowingMonPic_0126_ClickingSlurkerTiles[];
extern const u8 gShinyFollowingMonPic_0127_LuringSlurkerTiles[];
extern const u8 gShinyFollowingMonPic_0128_MedusalSlurkerTiles[];
extern const u8 gShinyFollowingMonPic_0129_PelletPosyTiles[];
extern const u8 gShinyFollowingMonPic_0130_MasterOnionTiles[];
extern const u8 gShinyFollowingMonPic_0131_OatchiTiles[];
extern const u8 gShinyFollowingMonPic_0132_QuaggledMireclopsTiles[];
extern const u8 gShinyFollowingMonPic_0133_AlbinoDwarfBulborbTiles[];
extern const u8 gShinyFollowingMonPic_0134_HairyBulborbTiles[];
extern const u8 gShinyFollowingMonPic_0135_WhiptongueBulborbTiles[];
extern const u8 gShinyFollowingMonPic_0136_OrangeBulborbTiles[];
extern const u8 gShinyFollowingMonPic_0137_WhitePikminTiles[];
extern const u8 gShinyFollowingMonPic_0138_BluePikminTiles[];
extern const u8 gShinyFollowingMonPic_0139_RockPikminTiles[];
extern const u8 gShinyFollowingMonPic_0140_YellowPikminTiles[];
extern const u8 gShinyFollowingMonPic_0141_WingedPikminTiles[];
extern const u8 gShinyFollowingMonPic_0142_RedPikminTiles[];
extern const u8 gShinyFollowingMonPic_0143_PurplePikminTiles[];
extern const u8 gShinyFollowingMonPic_0144_WaterWraithTiles[];
extern const u8 gShinyFollowingMonPic_0145_TitanDweevilTiles[];
extern const u8 gShinyFollowingMonPic_0146_PlasmWraithTiles[];
extern const u8 gShinyFollowingMonPic_0147_IcePikminTiles[];
extern const u8 gShinyFollowingMonPic_0148_GlowSeedTiles[];
extern const u8 gShinyFollowingMonPic_0149_GlowPikminTiles[];
extern const u8 gShinyFollowingMonPic_0150_SmokyProggTiles[];
extern const u8 gShinyFollowingMonPic_0151_MamutaTiles[];
extern const u8 gShinyFollowingMonPic_0152_MossTiles[];
extern const u8 gShinyFollowingMonPic_0153_ToyBorbTiles[];
extern const u8 gShinyFollowingMonPic_0154_BulblordTiles[];
extern const u8 gShinyFollowingMonPic_0155_PinchipedeTiles[];
extern const u8 gShinyFollowingMonPic_0156_LargeMothWollyhopTiles[];
extern const u8 gShinyFollowingMonPic_0157_ToyBlowhogTiles[];
extern const u8 gShinyFollowingMonPic_0158_TelescopingPumphogTiles[];
extern const u8 gShinyFollowingMonPic_0159_BeebTiles[];
extern const u8 gShinyFollowingMonPic_0160_BladedBeebTiles[];
extern const u8 gShinyFollowingMonPic_0161_StuddedBeebTiles[];
extern const u8 gShinyFollowingMonPic_0162_FireflapBulborbTiles[];
extern const u8 gShinyFollowingMonPic_0163_IceblownDweevilTiles[];
extern const u8 gShinyFollowingMonPic_0164_SpectralidTiles[];
extern const u8 gShinyFollowingMonPic_0165_BlubbugTiles[];
extern const u8 gShinyFollowingMonPic_0166_PuffyBlubbugTiles[];
extern const u8 gShinyFollowingMonPic_0167_StuffedBellbloomTiles[];
extern const u8 gShinyFollowingMonPic_0168_CentipareTiles[];
extern const u8 gShinyFollowingMonPic_0169_AdultCentipareTiles[];
extern const u8 gShinyFollowingMonPic_0170_WateryBlowhogTiles[];
extern const u8 gShinyFollowingMonPic_0171_GrabbitTiles[];
extern const u8 gShinyFollowingMonPic_0172_CoppellerTiles[];
extern const u8 gShinyFollowingMonPic_0173_MuggonflyTiles[];
extern const u8 gShinyFollowingMonPic_0174_ElectricCottonadeTiles[];
extern const u8 gShinyFollowingMonPic_0175_WaddlepusTiles[];
extern const u8 gShinyFollowingMonPic_0176_CrammedWraithTiles[];
extern const u8 gShinyFollowingMonPic_0177_BerserkLeechHydroeTiles[];
extern const u8 gShinyFollowingMonPic_0178_PebblePitcherTiles[];
extern const u8 gShinyFollowingMonPic_0189_AncientSirehoundTiles[];
extern const u8 gShinyFollowingMonPic_0180_CourageReactorTiles[];
extern const u8 gShinyFollowingMonPic_0181_AssembledCourageTiles[];
extern const u8 gShinyFollowingMonPic_0182_RememberedOldBuddyTiles[];
extern const u8 gShinyFollowingMonPic_0183_BulborbWithAGunTiles[];
extern const u8 gShinyFollowingMonPic_0184_KirbyTiles[];
extern const u8 gShinyFollowingMonPic_0185_SoulTiles[];
extern const u8 gShinyFollowingMonPic_0000_PlaceholderLarvaTiles[];
extern const u8 gShinyFollowingMonPic_0186_Demo77Tiles[];
extern const u8 gShinyFollowingMonPic_0187_UsubaTiles[];
extern const u8 gShinyFollowingMonPic_0188_KakureimoTiles[];
extern const u8 gShinyFollowingMonPic_0189_PikutabeTiles[];
extern const u8 gShinyFollowingMonPic_0190_NamaPongashiTiles[];
extern const u8 gShinyFollowingMonPic_0191_ChappyProtoTiles[];
extern const u8 gShinyFollowingMonPic_0412_EggTiles[];
extern const u8 gShinyFollowingMonPic_0192_RedBubblimpTiles[];
extern const u8 gShinyFollowingMonPic_0193_StarnacleTiles[];
extern const u8 gShinyFollowingMonPic_0194_ShearfleaTiles[];
extern const u8 gShinyFollowingMonPic_0195_WhiskerPillarTiles[];
extern const u8 gShinyFollowingMonPic_0196_IcyBlowhogTiles[];
extern const u8 gShinyFollowingMonPic_0212_FreezecakeTiles[];
extern const u8 gShinyFollowingMonPic_0213_ShockcakeTiles[];
extern const u8 gShinyFollowingMonPic_0214_WideMouthedAnodeBeetleTiles[];
extern const u8 gShinyFollowingMonPic_0215_DecoratedCannonBeetleTiles[];
extern const u8 gShinyFollowingMonPic_0208_AntennaBeetleTiles[];
extern const u8 gShinyFollowingMonPic_0142_RedPikminVeteranTiles[];
extern const u8 gShinyFollowingMonPic_0145_TitanDweevilElectricTiles[];
extern const u8 gShinyFollowingMonPic_0145_TitanDweevilFireTiles[];
extern const u8 gShinyFollowingMonPic_0145_TitanDweevilPoisonTiles[];
extern const u8 gShinyFollowingMonPic_0145_TitanDweevilWaterTiles[];
extern const u8 gShinyFollowingMonPic_0165_SpectralidRedTiles[];
extern const u8 gShinyFollowingMonPic_0165_SpectralidYellowTiles[];
extern const u8 gShinyFollowingMonPic_0165_SpectralidUnmarkedTiles[];
extern const u8 gShinyFollowingMonPic_0165_SpectralidUnmarkedRedTiles[];
extern const u8 gShinyFollowingMonPic_0165_SpectralidUnmarkedPurpleTiles[];
extern const u8 gShinyFollowingMonPic_0165_SpectralidElectricTiles[];
extern const u8 gShinyFollowingMonPic_0165_SpectralidHey0Tiles[];
extern const u8 gShinyFollowingMonPic_0165_SpectralidHey1Tiles[];
extern const u8 gShinyFollowingMonPic_0179_AncientSirehoundIceTiles[];
extern const u8 gShinyFollowingMonPic_0179_AncientSirehoundElectricTiles[];
extern const u8 gShinyFollowingMonPic_0179_AncientSirehoundFireTiles[];
extern const u8 gShinyFollowingMonPic_0179_AncientSirehoundGloomTiles[];
extern const u8 gShinyFollowingMonPic_0184_KirbyFlyingTiles[];
extern const u8 gShinyFollowingMonPic_0184_KirbyGrassTiles[];
extern const u8 gShinyFollowingMonPic_0184_KirbyBugTiles[];
extern const u8 gShinyFollowingMonPic_0184_KirbyPoisonTiles[];
extern const u8 gShinyFollowingMonPic_0184_KirbyWaterTiles[];
extern const u8 gShinyFollowingMonPic_0184_KirbyIceTiles[];
extern const u8 gShinyFollowingMonPic_0184_KirbyFireTiles[];
extern const u8 gShinyFollowingMonPic_0184_KirbyElectricTiles[];
extern const u8 gShinyFollowingMonPic_0184_KirbyFightingTiles[];
extern const u8 gShinyFollowingMonPic_0184_KirbyRockTiles[];
extern const u8 gShinyFollowingMonPic_0184_KirbyGroundTiles[];
extern const u8 gShinyFollowingMonPic_0184_KirbyPsychicTiles[];
extern const u8 gShinyFollowingMonPic_0184_KirbyGhostTiles[];
extern const u8 gShinyFollowingMonPic_0184_KirbyDragonTiles[];
extern const u8 gShinyFollowingMonPic_0184_KirbyDarkTiles[];
extern const u8 gShinyFollowingMonPic_0184_KirbySteelTiles[];
extern const u8 gShinyFollowingMonPic_0184_KirbyFairyTiles[];
extern const u8 gShinyFollowingMonPic_0185_SoulRedTiles[];
extern const u8 gShinyFollowingMonPic_0185_SoulYellowTiles[];
extern const u8 gShinyFollowingMonPic_0185_SoulBlueTiles[];
extern const u8 gShinyFollowingMonPic_0185_SoulPurpleTiles[];
extern const u8 gShinyFollowingMonPic_0185_SoulWhiteTiles[];
extern const u8 gShinyFollowingMonPic_0185_SoulRockTiles[];
extern const u8 gShinyFollowingMonPic_0185_SoulWingedTiles[];
extern const u8 gShinyFollowingMonPic_0185_SoulIceTiles[];
extern const u8 gShinyFollowingMonPic_0164_IceblownDweevilFireTiles[];
extern const u8 gShinyFollowingMonPic_0164_IceblownDweevilElectricTiles[];
extern const u8 gShinyFollowingMonPic_0164_IceblownDweevilWaterTiles[];
extern const u8 gShinyFollowingMonPic_0164_IceblownDweevilPoisonTiles[];
extern const u8 gShinyFollowingMonPic_0197_MysteriousLifeFormTiles[];
extern const u8 gShinyFollowingMonPic_0197_MysteriousLifeFormBulborbTiles[];
extern const u8 gShinyFollowingMonPic_0197_MysteriousLifeFormAmpratTiles[];
extern const u8 gShinyFollowingMonPic_0197_MysteriousLifeFormDandelflyTiles[];
extern const u8 gShinyFollowingMonPic_0197_MysteriousLifeFormArachnodeTiles[];
extern const u8 gShinyFollowingMonPic_0197_MysteriousLifeFormBlowhogTiles[];
extern const u8 gShinyFollowingMonPic_0198_PeteyPirannhaTiles[];
extern const u8 gShinyFollowingMonPic_0199_ToyPikminRedTiles[];
extern const u8 gShinyFollowingMonPic_0199_ToyPikminYellowTiles[];
extern const u8 gShinyFollowingMonPic_0199_ToyPikminBlueTiles[];
extern const u8 gShinyFollowingMonPic_0200_PikiMaleTiles[];
extern const u8 gShinyFollowingMonPic_0200_PikiFemaleTiles[];
extern const u8 gShinyFollowingMonPic_0201_DemoFTiles[];
extern const u8 gShinyFollowingMonPic_0202_DemoGTiles[];
extern const u8 gShinyFollowingMonPic_0203_DemoITiles[];
extern const u8 gShinyFollowingMonPic_0204_DemoWTiles[];
extern const u8 gShinyFollowingMonPic_0205_UsualSuspectTiles[];
extern const u8 gShinyFollowingMonPic_0206_MeteorTiles[];
extern const u8 gShinyFollowingMonPic_0207_CherryTiles[];
extern const u8 gShinyFollowingMonPic_0209_FieryYoungYellowWollyhopTiles[];
extern const u8 gShinyFollowingMonPic_0210_HotelTransylvaniaTiles[];
extern const u8 gShinyFollowingMonPic_0211_CalyrexTiles[];
extern const u8 gShinyFollowingMonPic_0216_SkeleminTiles[];
extern const u8 gShinyFollowingMonPic_0217_MoyaiminTiles[];
extern const u8 gShinyFollowingMonPic_0218_CockatriceTiles[];
extern const u8 gShinyFollowingMonPic_0219_BupborbTiles[];
extern const u8 gShinyFollowingMonPic_0220_DwarfKermitTiles[];
extern const u8 gShinyFollowingMonPic_0221_BulblaxLarvaTiles[];
extern const u8 gShinyFollowingMonPic_0222_CoalBeetleTiles[];
extern const u8 gShinyFollowingMonPic_0223_HeavyCannonLarvaTiles[];
extern const u8 gShinyFollowingMonPic_0224_CrewmateTiles[];
extern const u8 gShinyFollowingMonPic_0225_ImposterTiles[];
extern const u8 gShinyFollowingMonPic_0226_ApacheTiles[];
extern const u8 gShinyFollowingMonPic_0227_MorshubugTiles[];
extern const u8 gShinyFollowingMonPic_0228_SkitterjuanaTiles[];
extern const u8 gShinyFollowingMonPic_0229_WahpoleTiles[];
extern const u8 gShinyFollowingMonPic_0230_WaluigiwogTiles[];
extern const u8 gShinyFollowingMonPic_0231_StephanTiles[];
extern const u8 gShinyFollowingMonPic_0232_LinkgretTiles[];
extern const u8 gShinyFollowingMonPic_0233_OliManAtLegsTiles[];
extern const u8 gShinyFollowingMonPic_0234_BulbeelTiles[];
extern const u8 gShinyFollowingMonPic_0235_IwagenTiles[];
extern const u8 gShinyFollowingMonPic_0236_128MariosTiles[];
extern const u8 gShinyFollowingMonPic_0237_FiddleheadTiles[];
extern const u8 gShinyFollowingMonPic_0238_HorsetailTiles[];
extern const u8 gShinyFollowingMonPic_0239_SpotcapTiles[];
extern const u8 gShinyFollowingMonPic_0240_KingcapTiles[];
extern const u8 gShinyFollowingMonPic_0241_BulbieTiles[];
extern const u8 gShinyFollowingMonPic_0242_SlugcatTiles[];
extern const u8 gShinyFollowingMonPic_0243_PinkElebitTiles[];
extern const u8 gShinyFollowingMonPic_0244_PrimalAspidTiles[];
extern const u8 gShinyFollowingMonPic_0245_ChibiRoboTiles[];
extern const u8 gShinyFollowingMonPic_0246_PikachuTiles[];
extern const u8 gShinyFollowingMonPic_0150_SmokyProgMasterTiles[];

#endif // FOLLOWER_MON_SPRITES_H

