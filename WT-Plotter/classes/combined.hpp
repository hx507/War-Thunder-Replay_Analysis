#include "constants.h"
#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QMap>
#include <QPair>
#include <QString>

namespace Constants {
enum class Difficulty : int { ARCADE = 0, REALISTIC = 5, SIMULATOR = 10 };

inline const QMap<QString, QString> mapHashes = {
    QPair<QString, QString>(u"3a6b992635cb471d0d435eec3f28ee815d832f0a6666412ac6dce2e80", u"air_afghan_map"),
    QPair<QString, QString>(u"15ee03fc1ff41ec8be666cc5d379e73517188c68dea2bc373878ca368", u"air_africa_desert_map"),
    QPair<QString, QString>(u"766d989f56368aece619d13226548d001a5049f0a7616dc627c20d008", u"air_denmark_map"),
    QPair<QString, QString>(u"84b881b90df00ff01fc817c41f01bc01e281c8a7e2ac41280900080c0", u"air_equatorial_island_map"),
    QPair<QString, QString>(u"33eca388d30193c3924790b780fd14d593ad69ced193e26387070a0c0", u"air_grand_canyon_map"),
    QPair<QString, QString>(u"50465019202400c101010542408043818e019c83090e34884110c30c8", u"air_israel_map"),
    QPair<QString, QString>(u"6e07bca6e1d3c6229c263448a892d1632706941cf01fc09e03b206588", u"air_kamchatka_map"),
    QPair<QString, QString>(u"5846f888f80af84bec93589f60f2ca22738e14cd1d483a20b45509880", u"air_ladoga_map"),
    QPair<QString, QString>(u"5123690174805c84e29c359912da835b2b452112646cf0e843928e4b0", u"air_mysterious_valley_map"),
    QPair<QString, QString>(u"4a3030084983bf387c5ba1c6850d9893629407aa0b88270ea3a657bf0", u"air_normandy_map"),
    QPair<QString, QString>(u"58123934a09b144356a418d915b03b28db823a2ba389265826e2a4690", u"air_pyrenees_map"),
    QPair<QString, QString>(u"2a114c100eb07a408e433dc1e1e253c25606bc09f912618cf319a4820", u"air_race_phiphi_islands_map"),
    QPair<QString, QString>(u"c50f091356a26e6cc8db20b609b4537990e331d6618e431ca6b98d330", u"air_skyscraper_city_map"),
    QPair<QString, QString>(u"102cc0d3c545c1cb13261f281e4c18c3a5078024c0e9b3c423104cc00", u"air_smolensk_map"),
    QPair<QString, QString>(u"63990ebec53783d5825d94bb9b23accfcd0790e360b30544cd0b07608", u"air_southeastern_cliffs_map"),
    QPair<QString, QString>(u"c645b626e88ccd21a328c60384049c13701fd03f00210000000080020", u"air_south_eastern_city_map"),
    QPair<QString, QString>(u"2eba056c2f7ca693662cc45108e89cd0df40ff016306c08c92190d1a0", u"air_vietnam_map"),
    QPair<QString, QString>(u"429e357e19ff337d8d7a99d6cfac9f293f251e726cd4fe69bcfbfac30", u"arcade_africa_canyon_map"),
    QPair<QString, QString>(u"c4d289c912f4146818f95160a5714c819b0d8f2a5c33b826732a33188", u"arcade_africa_seashore_map"),
    QPair<QString, QString>(u"418283858e0b9831616282c6118a330e463d853a0be1d9c3b786370e0", u"arcade_alps_map"),
    QPair<QString, QString>(u"7bc2f64de29e441d710ad20726134d6a8aed04de1fbd16da07985e390", u"arcade_asia_4roads_map"),
    QPair<QString, QString>(u"fd07e197e53f9927003e607da165e2e9c1fa17e40f7b1f7b0fe68fe60", u"arcade_canyon_snow_map"),
    QPair<QString, QString>(u"266a68dcacfc31f275ef23af33a54d71c86330d2e93196f26fc4cd1d8", u"arcade_ireland_map"),
    QPair<QString, QString>(u"836e4ee9c5eb4c9257b6c4d7672e8f4cdcb55da6cb6d625424f46b358", u"arcade_mediterranean_map"),
    QPair<QString, QString>(u"d86d3cf65dcd977e497586734ccb6ec42f593fa97f84fcc5332e2cca0", u"arcade_norway_fjords_map"),
    QPair<QString, QString>(u"8caaa75b64464904c508cab04c5850ab42ce88da02a94db18f62bac60", u"arcade_norway_green_map"),
    QPair<QString, QString>(u"1b660cc9cb6b1861448aca31a459c888308881f203c943a28e661ece0", u"arcade_norway_plain_map"),
    QPair<QString, QString>(u"7238e4fef44cad3329e5554a32992f2a822f346a3e30d5768e9588a60", u"arcade_phiphi_crater_map"),
    QPair<QString, QString>(u"0ff0a9acb38ad71553e665c253952f48bc89a416d9165686e9a7c3660", u"arcade_phiphi_crater_rocks_map"),
    QPair<QString, QString>(u"82ed30882b816b265e3474a9ed13a04b2736af6f44db4c6e47d20ae60", u"arcade_rice_terraces_map"),
    QPair<QString, QString>(u"12526b82e706fa89fd1dda3dbc7778ce719def1e6d6b19c66ace8d9d0", u"arcade_snow_rocks_map"),
    QPair<QString, QString>(u"01b082f005e00fe06fe05bc8e7894f003f00fd107a4872012000c0018", u"arcade_tabletop_mountain_map"),
    QPair<QString, QString>(u"64424aa4d518c87c7253647122498dcd308af08c219d4e2e024e46560", u"arcade_zhang_park_map"),
    QPair<QString, QString>(u"45265a9f99114921ce3b1d7036242e1ab4166096d29a4859c9b6684d8", u"avg_abandoned_factory_map"),
    QPair<QString, QString>(u"2a42552469888e3091a113c4230a861b4e7958312a489687084430690", u"avg_abandoned_factory_tankmap"),
    QPair<QString, QString>(u"222753668118542a95bb07372c74337e627844b5497d426accc8f5f60", u"avg_abandoned_town_map"),
    QPair<QString, QString>(u"932c3b5b5aa14cf5c7ff66dc47a62f3d2f2c683c55dd45644758da288", u"avg_abandoned_town_tankmap"),
    QPair<QString, QString>(u"d265b19ba67427394ebe125f5567086f16a71959c26958e999d4e59a0", u"avg_africa_desert_tankmap"),
    QPair<QString, QString>(u"a5921916134ca79a2f2efad96433c2262e9434eaa9e52ad4c5619d270", u"avg_alaska_town_map"),
    QPair<QString, QString>(u"acae989d893a9a7174e2b6457680ed15de1bfc5579cb730b6e27c94f8", u"avg_alaska_town_tankmap"),
    QPair<QString, QString>(u"f017c066a59c43309367754ee2dda44d229f473ea48c6b3c6630cc618", u"avg_american_valley_map"),
    QPair<QString, QString>(u"b71e46f98d9133946f2c6c78e861b9c665830f0d3a3536776696e72b0", u"avg_american_valley_tankmap"),
    QPair<QString, QString>(u"99cb316dd6f839397948d76bef2fc73fb24791bf35bcac6aa9a577ea8", u"avg_aral_sea_map"),
    QPair<QString, QString>(u"716ac8c5b750ad5adc34728b551e13bc8ef11cd9b9ab73c56ed96d938", u"avg_aral_sea_tankmap"),
    QPair<QString, QString>(u"5896cc19a2344b498d4109923ea36686a09a44d6c146ec45118a04620", u"avg_arctic_map"),
    QPair<QString, QString>(u"4b18aa6115e64dca8f945b4625523630fee0e98bda0774a6cd5489ac8", u"avg_arctic_tankmap"),
    QPair<QString, QString>(u"eca3b286229cc0e983b15e48fcb0ed2ef4f527cf6f5ac75d5ad407a98", u"avg_ardennes_map"),
    QPair<QString, QString>(u"aca33307221c80ed23f14e49f412cd2c747534cd6f1ac74d5ad405a98", u"avg_ardennes_snow_map"),
    QPair<QString, QString>(u"383ab9ef565ae3331caeb7185924b9a6b054e35586951d2edaacace98", u"avg_ardennes_snow_tankmap"),
    QPair<QString, QString>(u"381ed16f565ae53b1eaeb758792cb8a69154a35596911d2e5afcace98", u"avg_ardennes_tankmap"),
    QPair<QString, QString>(u"914cb995cb169c8845b34a84cc2192c5846b98a54dc6585ab87559230", u"avg_berlin_tankmap"),
    QPair<QString, QString>(u"519282a620a260b86127812d88b5081a2835134e00600aa5950996280", u"avg_breslau_map"),
    QPair<QString, QString>(u"f169c55310971598abc45bc2a5c16b48ad4caf4e5f51db615386d99c8", u"avg_breslau_tankmap"),
    QPair<QString, QString>(u"de6866eb94f1cbe91704ef23cc29bdb3b82ad9b4f4b0e966c78986170", u"avg_container_port_map"),
    QPair<QString, QString>(u"d909fa6696cc1e9127a8e740e601ec83b809721af017d43544af8c458", u"avg_container_port_tankmap"),
    QPair<QString, QString>(u"9e729ce995a131c2339413342346238b6240dd849c29840b2ca356a40", u"avg_eastern_europe_map"),
    QPair<QString, QString>(u"b67e927e7898e312a8b9316a66d791b371d00c348a119d29b7d669198", u"avg_eastern_europe_tankmap"),
    QPair<QString, QString>(u"0bf52fc73cc330d161c2e3a5ce39886348c611c6264c37987f18bb080", u"avg_egypt_sinai_map"),
    QPair<QString, QString>(u"b3628d89b37141d26df493ef75cd4b01975beeb5dd8bc436ca234a438", u"avg_egypt_sinai_tankmap"),
    QPair<QString, QString>(u"e589cb0b479cdb81867689216258cc8e998d3b6a34cf4b83da27ae260", u"avg_european_fortress_map"),
    QPair<QString, QString>(u"6ca0ed414278e4fdd1f8b3e2b7e66ac64d911f96a925e64691a5070a8", u"avg_european_fortress_tankmap"),
    QPair<QString, QString>(u"254821287158c4b827215a631412c23700ec974c52366654c4cc958d0", u"avg_finland_map"),
    QPair<QString, QString>(u"3731b8f6136c487805e097c527805f049801a0053009082490f021910", u"avg_finland_tankmap"),
    QPair<QString, QString>(u"00fe13fc12f86cf09de123d227a46f489e92bd227a68f05be017c05f8", u"avg_football_field_map"),
    QPair<QString, QString>(u"6cc7b183e6678d2e1bda26d4cde8b1c9aab14e25bf0b263a5e7832730", u"avg_fulda_map"),
    QPair<QString, QString>(u"904f04e81a9023b102e40f883e107c01f007591f325ca3f887f11f860", u"avg_fulda_tankmap"),
    QPair<QString, QString>(u"90f503d21b90eb62f293e6206490f1d0e290e054a691c5a30b2325518", u"avg_future_city_map"),
    QPair<QString, QString>(u"8e12cb1c60b0a3630ece3d85b30c47300e001c0048c471807200c0008", u"avg_greece_map"),
    QPair<QString, QString>(u"48ce196cb0caad90c72436d2ad85455a9b673637e4e19a736994c6318", u"avg_greece_tankmap"),
    QPair<QString, QString>(u"f0edd3f260b07331e382f19b31ec59c49941bf2495812ee0aa9018490", u"avg_guadalcanal_map"),
    QPair<QString, QString>(u"f97c7bbcea78ea321a26a742399d2b1156ab3184d0c999b9f155d0590", u"avg_guadalcanal_tankmap"),
    QPair<QString, QString>(u"42bd127c8731a2529435c137224dc7e3958e947118dcbe39292f405b8", u"avg_hurtgen_map"),
    QPair<QString, QString>(u"487223c5e5b30662794961cb6f1e9c7f38f720f723e9cf32198424e00", u"avg_hurtgen_tankmap"),
    QPair<QString, QString>(u"705d547b56ee907451e2b380a3018e0b1810001100020000000000000", u"avg_iberian_castle_map"),
    QPair<QString, QString>(u"1e2ec457487801b00362035c948523071e06a4051800f00e000000000", u"avg_iberian_castle_tankmap"),
    QPair<QString, QString>(u"f39f326f6c7ef0f7f236e0ed513395b6a1234f452c6416cdeccb9b3c8", u"avg_ireland_tankmap"),
    QPair<QString, QString>(u"60e588f229e24b8857041c4afc0df819f813f42b984f738ec65689ad8", u"avg_israel_map"),
    QPair<QString, QString>(u"6e9c9d71bee3dd837e0b7c4edc1db8ba7938f433b97f73d6c6ee8acd8", u"avg_israel_tankmap"),
    QPair<QString, QString>(u"11beb07eb545ca71e0e3c446d483948618036104c461a3c30dc61a9c0", u"avg_japan_map"),
    QPair<QString, QString>(u"4f271f013618e7158c831da629d93a31caf895c83b0928b711a6591a0", u"avg_japan_tankmap"),
    QPair<QString, QString>(u"73446f597859e32b8cdb127555666ad07741aadab566c685a168f8d80", u"avg_karantan_tankmap"),
    QPair<QString, QString>(u"1c70bae0f1c8e399cf03cf07192e383e70f961fa83f806790cf63d880", u"avg_karelia_forest_a_map"),
    QPair<QString, QString>(u"24cd28bf0e5459b99a7394f4af6bfcd2bc3d3a3ddeb37c4f3cf189f98", u"avg_karelia_forest_a_tankmap"),
    QPair<QString, QString>(u"66cc4367c677b5c3f91b7b336426e6e253e03190b1909029ae130bb98", u"avg_karpaty_passage_map"),
    QPair<QString, QString>(u"817f02df07bccb951d0ab812cb83b68f3b9c97597ff0be2c58d9a28d8", u"avg_karpaty_passage_tankmap"),
    QPair<QString, QString>(u"4c8a352858b0d0773078d9a19367a065409686cc1d182e308e459c928", u"avg_korea_lake_map"),
    QPair<QString, QString>(u"882334407a02a2005620a018c4d929da93c987eb077a0fc81d78164c0", u"avg_korea_lake_tankmap"),
    QPair<QString, QString>(u"c7838f873f1c7231c4b3cb6f20fe13f867fb4ff68ff21f267e04f01b8", u"avg_krymsk_tankmap"),
    QPair<QString, QString>(u"664ccc91ada359263b247074f1f8b9f0f3e0efecf56f48df91fa27ec0", u"avg_kursk_villages_tankmap"),
    QPair<QString, QString>(u"60e9439887118c631846020408039015205a274020046000402884400", u"avg_lazzaro_italy_map"),
    QPair<QString, QString>(u"d804902c93344e719ded21d07300f601dea3dc02f807701fa14d55b20", u"avg_lazzaro_italy_new_city_tankmap"),
    QPair<QString, QString>(u"0cb0086418d022a04e08d915100b8217b088481030256043009709220", u"avg_maginot_map"),
    QPair<QString, QString>(u"a446af4d64b224acb949518554b9a87bd293342a6c5d2d6c71f042e48", u"avg_maginot_tankmap"),
    QPair<QString, QString>(u"8e5910c071a1f38089c43df0e166c062816208c504e609300c8030000", u"avg_mozdok_tankmap"),
    QPair<QString, QString>(u"922596622a659609305571ee871a9275aa22a5984a34386c64c8b1f50", u"avg_netherlands_map"),
    QPair<QString, QString>(u"23f2e789acab6dd56faf9317a636a92d2e5ac93ddb96936af1b3476f8", u"avg_netherlands_tankmap"),
    QPair<QString, QString>(u"ed0244be9758cd41d3a59104e293443254a584ee08d610bc40b3d7a68", u"avg_normandy_tankmap"),
    QPair<QString, QString>(u"eba21650881bd055e213c2238c9b507548ea80c492c9249c43198e368", u"avg_northern_india_map"),
    QPair<QString, QString>(u"3181278dcd6bbcde585999bcb1edd6dae593cb33a6ea0d5cf85570bc0", u"avg_northern_india_tankmap"),
    QPair<QString, QString>(u"737dbde15fc0f80ae035efba91d6469a694b43a72b832b452d9873b08", u"avg_northern_valley_map"),
    QPair<QString, QString>(u"644e643caa32e4169a0eac32db327169298ad79ac7963b05b94b75568", u"avg_northern_valley_tankmap"),
    QPair<QString, QString>(u"a4ae989d893a9a7575e2b64576892d165a1bfc5579cb330b6e07c94f8", u"avg_nuclear_incident_tankmap"),
    QPair<QString, QString>(u"ed0090707ae1f0c3c79aaf4bc78f1e0d1e9e1c12382c301c200e40148", u"avg_poland_map"),
    QPair<QString, QString>(u"ed0091707ae1f1c3c79aaf4bc78f1e0d1e9e1c12382c301c200e40148", u"avg_poland_snow_map"),
    QPair<QString, QString>(u"1c0a80ca5175c2168ea6144c5e1f1c6e341e656cca7f44f083f086fc8", u"avg_poland_snow_tankmap"),
    QPair<QString, QString>(u"c3f51fc43cc8f9237b18e2b1e3e2c385872c8e113c00f601b69b79150", u"avg_poland_tankmap"),
    QPair<QString, QString>(u"4bba8f6d0fa62b44839b99f18cb3ca278207000c30002000000000000", u"avg_port_novorossiysk_map"),
    QPair<QString, QString>(u"28d313c21e96482d4e117024e05780ae01d8019a13bc818e039801f00", u"avg_port_novorossiysk_tankmap"),
    QPair<QString, QString>(u"489b331c5a3855d96ab8d331ea29cf56aa0f24162e6c18ea73136a648", u"avg_red_desert_map"),
    QPair<QString, QString>(u"718b8a86d6878b1d72929413a42ae597159a42eda7a24c5d2d900c388", u"avg_red_desert_tankmap"),
    QPair<QString, QString>(u"b033e4637036e0c9c011e0b3f373c4f58de313e287c70fc65f823f060", u"avg_rheinland_map"),
    QPair<QString, QString>(u"9765964f26af6b4eaa5e977e32fc79f86acbc766cd23934eaf836b060", u"avg_rheinland_tankmap"),
    QPair<QString, QString>(u"cd891182b125322a3c5d96bd1655033b4c77646e50bad09e981c311b8", u"avg_sector_montmedy_map"),
    QPair<QString, QString>(u"cd891082b125322a3c5d96bd165503bb4d77606e509ad09e901d311b8", u"avg_sector_montmedy_snow_map"),
    QPair<QString, QString>(u"2410c8309231ae415cca2c942218a6390c623b00d6262c443928f0c88", u"avg_sector_montmedy_snow_tankmap"),
    QPair<QString, QString>(u"2650cc309820a041c4ca29942308a6390862338096261c44f028f0408", u"avg_sector_montmedy_tankmap"),
    QPair<QString, QString>(u"6272d5e476469b030d4cd13302e473a1ee86ce4699856d9ba90aea1b0", u"avg_snow_alps_map"),
    QPair<QString, QString>(u"9c1d0cc811f45ba87488f213b66d4c365c729cc93989932c00be81dd8", u"avg_snow_alps_tankmap"),
    QPair<QString, QString>(u"21206b24331c27928a6cd07b5430a64e2b8568524dce692ac2a1bc668", u"avg_soviet_range_map"),
    QPair<QString, QString>(u"38aa133c12cb6593dc6caddc58b2b32566421de433589645a92589c10", u"avg_soviet_range_tankmap"),
    QPair<QString, QString>(u"71216243221347048a49a5329c3515c8b16148c55d894d689ea11c440", u"avg_soviet_suburban_map"),
    QPair<QString, QString>(u"33235d44b39b67128a2dc57b9835149a3b456cf15d8c49aaaac17b468", u"avg_soviet_suburban_snow_map"),
    QPair<QString, QString>(u"c5e125e6c2db25764b8eb72f545c896903c38251a86010d870b0f1500", u"avg_soviet_suburban_snow_tankmap"),
    QPair<QString, QString>(u"f2d540c283b992726ad525ce2bb04b61b6572a394b78b339375328750", u"avg_soviet_suburban_tankmap"),
    QPair<QString, QString>(u"238302c18a7ec2b10d627650eda7b137c65f99fee7e78f5c0ef01ec08", u"avg_stalingrad_factory_tankmap"),
    QPair<QString, QString>(u"0136026e139c1e7498f15bd097a12f4a3e2e7c01fa6ff9afe317c43f8", u"avg_sweden_map"),
    QPair<QString, QString>(u"43d003e603f031f053e257c07f80ff01fe03fc2ff81bf02fc04f903d0", u"avg_sweden_tankmap"),
    QPair<QString, QString>(u"d2c9f123aa2cb0d1638867104e625c79d4cf135a29d4b7b1b2e465920", u"avg_syria_map"),
    QPair<QString, QString>(u"5d18f638f01869b273add64448098d152eacfa11e19d031a04bc03600", u"avg_syria_tankmap"),
    QPair<QString, QString>(u"b67f68fca0ea49939636166d0af84df25bc6378c6f89de93b9a1e7650", u"avg_training_ground_tankmap"),
    QPair<QString, QString>(u"e1c6837c47d00f807e037c02f08de023e087c08fc10f801f827f80d70", u"avg_tunisia_desert_map"),
    QPair<QString, QString>(u"ce0f3cbe75b7eaffd0f5b9e47f14be8a9d619f633f7af9b3f3c4ef8f8", u"avg_tunisia_desert_tankmap"),
    QPair<QString, QString>(u"0cbe19fc5f782ef46fe93f9cbf3dfe39fc7270fe46f88c70186034000", u"avg_vietnam_hills_map"),
    QPair<QString, QString>(u"5b80c5c595d82c7858e30f849b04b68c270c3f0d725ce0cb820f08f78", u"avg_vietnam_hills_tankmap"),
    QPair<QString, QString>(u"4038005401a802c005800bc012802980c3811b826720de600ec029820", u"avg_vlaanderen_map"),
    QPair<QString, QString>(u"6672aa6764b258b2dac22f0a23506ab19956dc6da490c964330952548", u"avg_vlaanderen_tankmap"),
    QPair<QString, QString>(u"e651c5230296184e989d63ad435a96d52d6658c4d49c4d541a4b38660", u"avg_volokolamsk_map"),
    QPair<QString, QString>(u"2b00cdc8f1627568d60b0a0669b6449c5c8db9c2f0ec645bc383a0488", u"avg_volokolamsk_tankmap"),
    QPair<QString, QString>(u"8517855987e6a15916995642d8d313a7313c72596118be39306c95198", u"avg_western_europe_map"),
    QPair<QString, QString>(u"296a0eb524aac9d79bc6f605e88eb16d8ad91554a85a1084691d966c8", u"avg_western_europe_tankmap"),
    QPair<QString, QString>(u"062e003c28783c507c20dc41bc825c80dc019c4038407461620911228", u"avn_africa_gulf_map"),
    QPair<QString, QString>(u"fc09c942030a11681e401f803f8c6308ce559ca7f94bf077f16fe25f0", u"avn_africa_gulf_tankmap"),
    QPair<QString, QString>(u"d087302ee09e803c383871e00cc07b0c7071f040b8a17832c066be290", u"avn_aleutian_islands_map"),
    QPair<QString, QString>(u"02d30de755f6a9f973e097c0af80bf037e027e05f001c012144804540", u"avn_aleutian_islands_tankmap"),
    QPair<QString, QString>(u"2ae2c7c416018a43150210262029401080548024006e0880036005200", u"avn_alps_fjord_map"),
    QPair<QString, QString>(u"0d9619ac33884298951128f054b1b53126a16b51b4c1d380c04d20ce0", u"avn_alps_fjord_tankmap"),
    QPair<QString, QString>(u"0f081d48b8cbcc37ac6870a1cbb64b98c9c988ee09db93e7209d40b30", u"avn_arabian_north_coast_map"),
    QPair<QString, QString>(u"394d32326868849e2a6eb459ca4c28a9499890c91866983c42d222738", u"avn_arabian_north_coast_tankmap"),
    QPair<QString, QString>(u"d80b3036e16e623aa034642364c6098d19125630d442e80e100a36790", u"avn_bering_sea_map"),
    QPair<QString, QString>(u"d86532f2a447088c137830f03349a301ea61de625480a832906416398", u"avn_bering_sea_tankmap"),
    QPair<QString, QString>(u"15617b126108e40a6b05cb07a50e2a9d95daab2338825489b5b550e30", u"avn_blacksea_port_map"),
    QPair<QString, QString>(u"10c03180d217212c4d086212d54c865528a158709ca21e2a39a473ad8", u"avn_blacksea_port_tankmap"),
    QPair<QString, QString>(u"14526a43688a6494ad2c1918de1038246521fa64f46548a10c06151d0", u"avn_coral_islands_map"),
    QPair<QString, QString>(u"006008c0158097021981d1832606761cd83aa84ab007e0196011c0000", u"avn_coral_islands_tankmap"),
    QPair<QString, QString>(u"99a823cb6395bf2eff09bc10f8a7e09f20a7289f255e0dbc2a7835788", u"avn_england_shore_map"),
    QPair<QString, QString>(u"f1a7f24ed11d865f4d9f126e2cd63bfa9b89cf16965d889a001d42138", u"avn_england_shore_tankmap"),
    QPair<QString, QString>(u"80a48828207101f045e807d04f307c62e0c7e11fc03f807cb07020500", u"avn_fiji_map"),
    QPair<QString, QString>(u"7000e413120046020b085f10ce033e823901e003000e889938007c048", u"avn_fiji_tankmap"),
    QPair<QString, QString>(u"15b249c19946960c5b189a765432984b68b2504090813812c06492218", u"avn_finland_islands_map"),
    QPair<QString, QString>(u"086c198ea63c972a2cc13ac3af87870f0e1e1c7838e03020b44804540", u"avn_finland_islands_tankmap"),
    QPair<QString, QString>(u"c3a746954a4d4675a33333070d695cb6f035f061b0817032c06496798", u"avn_franz_josef_land_map"),
    QPair<QString, QString>(u"01fe0ffc1df819f031e075c0ab85df027e06fc05f803e017b04f007c0", u"avn_franz_josef_land_tankmap"),
    QPair<QString, QString>(u"634906ab5a2b1a3038f993fbe697e57bc879c9e29a1d9438ca53b9830", u"avn_fuego_islands_map"),
    QPair<QString, QString>(u"ff801f05e71ace1ec43d81cf332ec23d88dd0baf1d1e351c279837140", u"avn_fuego_islands_tankmap"),
    QPair<QString, QString>(u"13520d241288339096614c82110091300e2038146018200022094c368", u"avn_ice_port_map"),
    QPair<QString, QString>(u"2c40490c34f8e860cb013b053602bc308822180410190006460c4c188", u"avn_ice_port_tankmap"),
    QPair<QString, QString>(u"cc4c8c9165e186971964b2d1a356071d4830d1609a3198e04a1290838", u"avn_ireland_bay_map"),
    QPair<QString, QString>(u"af6b985b708a184839a17b02cc051e049e12fe30f879f6bbfb7dbb7c0", u"avn_ireland_bay_tankmap"),
    QPair<QString, QString>(u"f16530c864e099c0330087231c2298d2b990f150b091f83a406416698", u"avn_japan_map"),
    QPair<QString, QString>(u"395073815512b899e335410d580cb8117046f409b8307070e1e5c46b8", u"avn_japan_tankmap"),
    QPair<QString, QString>(u"a66c552a1ac666e4cdc99629ac4df8a96150d1b096b12c92d44492590", u"avn_mediterranean_port_map"),
    QPair<QString, QString>(u"d6f1edc0eb01c6034c855120d8c021004100968114020204461650940", u"avn_mediterranean_port_tankmap"),
    QPair<QString, QString>(u"c49269441e986411e169808e20b9a0cb21844108987110e0214090100", u"avn_new_zealand_map"),
    QPair<QString, QString>(u"b272247748e7254e7238c02ea83861c821815068b95130a420c4a3100", u"avn_new_zealand_tankmap"),
    QPair<QString, QString>(u"266209cc960f59458999953105c689c4b3459e242c4f5048909151108", u"avn_northwestern_islands_map"),
    QPair<QString, QString>(u"c842a405a1058e40ce434e004c438e573f346b037003e001c000e2808", u"avn_northwestern_islands_tankmap"),
    QPair<QString, QString>(u"20c0008001a00170c2e1814601ac0fd90f2d27496c80d6202f104d718", u"avn_north_sea_map"),
    QPair<QString, QString>(u"c283ccc79ecd3999e32b36f57ce6bfca7f15ef251f63984d587451608", u"avn_north_sea_tankmap"),
    QPair<QString, QString>(u"b672ed5cf4c9a9636964a4521906720524c963124e0abc4549b3b1ad0", u"avn_norway_islands_map"),
    QPair<QString, QString>(u"c5d86364fcccf113c26c8cb98a62a9d32738d371a7826138a2b208c40", u"avn_norway_islands_tankmap"),
    QPair<QString, QString>(u"d87d313ae077087c38f8f9e03148fa01a8725c6038a07821c047964d8", u"avn_peleliu_map"),
    QPair<QString, QString>(u"00fe017c0cf819f03be09bc08f839f053e01fc05f817f02fe01f807e8", u"avn_peleliu_tankmap"),
    QPair<QString, QString>(u"18f4a169c4e29b947c04d30bae165e20946128b7499a735aa6a202cc0", u"avn_phang_nga_bay_islands_map"),
    QPair<QString, QString>(u"b7454e51348d1b105c055813381b61b20335021c86700e280ce019c80", u"avn_phang_nga_bay_islands_tankmap"),
    QPair<QString, QString>(u"3253a086cd0d4a5996491371caf098c05981fa0372046808f6315d728", u"avn_san_francisco_map"),
    QPair<QString, QString>(u"442b6865942f6841d980c7818f511c80179097262e4e5c11dc3b9d750", u"avn_san_francisco_tankmap"),
    QPair<QString, QString>(u"5e3f393c18f93af4d5ce2d13fc61f800f853f450b811f832446616698", u"avn_south_africa_map"),
    QPair<QString, QString>(u"8bfecb7f9efc5ffb03e667c0b5817303260f841f383e603e007800780", u"avn_south_africa_tankmap"),
    QPair<QString, QString>(u"a72a23a917782ec29d451b0927b08ee3198c820000000000000000000", u"avn_sunken_city_map"),
    QPair<QString, QString>(u"9936b9c0bca5c997a42da61c84fe5272b8caccda44998e191c241ac40", u"avn_sunken_city_tankmap"),
    QPair<QString, QString>(u"c12854545b88979a0b641a597680ef40d45e889914a70913328413340", u"avn_volcanic_island_map"),
    QPair<QString, QString>(u"b66dad0d52dc6b1b293a775c35552068d75b8a4cae4a459967449eaa0", u"avn_volcanic_island_tankmap"),
    QPair<QString, QString>(u"32064430400d42936546f08cb4ac7824b6ca7355d50ca5162a6404ab0", u"berlin_map"),
    QPair<QString, QString>(u"381ca23b9c7f7aff7dc45f997e20fc27f28f22b0954102c2118820900", u"britain_map"),
    QPair<QString, QString>(u"1946342cf069a1510fb53e49d606ea4f9f067947f0afa017630cc12e8", u"bulge_map"),
    QPair<QString, QString>(u"6544bb0c1874404886c11f0816006a05dc1ec1a98e5ee323c599fa4e0", u"caribbean_islands_map"),
    QPair<QString, QString>(u"e201900200033009603fc047818e02e001c00001a801c009ca07c9058", u"dover_strait_map"),
    QPair<QString, QString>(u"ba95d1933626689938b1c48638943af663b8e9b1d375a5a743431ea68", u"firing_range_tankmap"),
    QPair<QString, QString>(u"f0e9d3fa61b071f0e0e1e15b329c593cf279bc7d90bd21dee06ec25e8", u"guadalcanal_map"),
    QPair<QString, QString>(u"407d80fa01f421f8c3e00f803f027507df17483ea07e817902e31e630", u"guam_map"),
    QPair<QString, QString>(u"0eb99dd30e241e083c1338a17f617fc27ec47dc1f38ce383860706af8", u"honolulu_map"),
    QPair<QString, QString>(u"272b5615b421ae56ac33927664cdc3c3038e247398ddba297925506f8", u"hurtgen_map"),
    QPair<QString, QString>(u"4d085e047a18d032c3bc29a43848f231b20548b891ec70f820f040ec8", u"iwo_jima_map"),
    QPair<QString, QString>(u"1401c8339a67189e19a712236c46709d103c603800370133ce7c3cd00", u"khalkhin_gol_map"),
    QPair<QString, QString>(u"4d342558db6b174da5668b59ba331cda57a4ad04635ba16b14ac391d0", u"korea_map"),
    QPair<QString, QString>(u"ad225f05b283678c4ed48cf1336264451b1126922d464c1b9e11b8ad0", u"korsun_map"),
    QPair<QString, QString>(u"03ca8ff20fc21f863f853d438d051c810de241f804c6180e2216084b0", u"krymsk_map"),
    QPair<QString, QString>(u"cb03ad2268949d461d212ccb56c6c9c9b2c75794ee61adc797261c648", u"kursk_map"),
    QPair<QString, QString>(u"a0f181e426907104f100f9007004b8a1f981fbc0e3c686e00c7008580", u"malta_map"),
    QPair<QString, QString>(u"02fe01fc03f80ff00f901fc07fc07f00fc01f8037806f00f601880270", u"midway_map"),
    QPair<QString, QString>(u"0cf35decfba47e1cd5156bf2bad4f4ecf5d5cfad9f58d5642076a2eb0", u"moscow_map"),
    QPair<QString, QString>(u"e9bedafdf75b8b75f0fcfe41df8fef07bd17d6afd297e5235e4b849e8", u"mozdok_map"),
    QPair<QString, QString>(u"c9fe7aac6bd98bf4f0eb1e78c3f033980cf8c4b054403aa3b64b249e8", u"mozdok_winter_map"),
    QPair<QString, QString>(u"8644869b06261cec5188887209e312cb6982c906062d0c5a18f9330a0", u"norway_map"),
    QPair<QString, QString>(u"65d062a4836b24d34bc64ed71c4c78b4b907108ba04419b039a2ddf08", u"peleliu_map"),
    QPair<QString, QString>(u"a404140388058205842b80930017042608151a410b611cc9152910ca0", u"port_moresby_map"),
    QPair<QString, QString>(u"006c10ca164618c4256c615c42284b304c6132c08e803d813f821f000", u"ruhr_map"),
    QPair<QString, QString>(u"65d062a4836b24d34b465cb7344dd8b3b903108ba04419b039e2ddd08", u"saipan_map"),
    QPair<QString, QString>(u"60ffa2ff17f44bd56faaef339eebbf295f917f53facbfe78e5ee8abb0", u"sicily_map"),
    QPair<QString, QString>(u"3f0cb61d683fa1ae88d955b4c36a9f873d5de09b953781ff06f87fc88", u"spain_map"),
    QPair<QString, QString>(u"82f886e1c7819a21fc01f877e1b78a3f503c227040dc11d803c800d80", u"stalingrad_map"),
    QPair<QString, QString>(u"82f886e1c7819b21fc01f873e0b7c03f403c227040fd31d803c900d80", u"stalingrad_w_map"),
    QPair<QString, QString>(u"0000000000000f002600c60098007005800b0016002c0000000000000", u"unknownmap"),
    QPair<QString, QString>(u"071206060a9c17282f203ca079c0e368f879ed75c35b87b710c6270a8", u"wake_island_map"),
    QPair<QString, QString>(u"50c7202e419ca1335064834a8d531ae135d05d4662890a24859324540", u"water_map"),
    QPair<QString, QString>(u"38e9c0628d9e022c89d4e321d21da16f187f7affefd9ecf8ccf9bcfe0", u"zhengzhou_map")
};
}

#endif  // CONSTANTS_H
#include "craftinfo.h"

CraftInfo::CraftInfo() {}

CraftInfo CraftInfo::fromJson(const QJsonObject& craftInfoObject) {
	CraftInfo craftInfo;

	if (craftInfoObject.contains("name") && craftInfoObject["name"].isString()) {
		craftInfo.name = craftInfoObject["name"].toString();
	}

	if (craftInfoObject.contains("type") && craftInfoObject["type"].isString()) {
		craftInfo.type = craftInfoObject["type"].toString();
	}

	if (craftInfoObject.contains("rankUnused") && craftInfoObject["rankUnused"].isBool()) {
		craftInfo.rankUnused = craftInfoObject["rankUnused"].toBool();
	}

	if (craftInfoObject.contains("mrank") && craftInfoObject["mrank"].isDouble()) {
		craftInfo.mrank = craftInfoObject["mrank"].toInt();
	}

	if (craftInfoObject.contains("rank") && craftInfoObject["rank"].isDouble()) {
		craftInfo.rank = craftInfoObject["rank"].toInt();
	}

	return craftInfo;
}

int CraftInfo::getRank() const {
	return rank;
}

int CraftInfo::getMrank() const {
	return mrank;
}

bool CraftInfo::isRankUnused() const {
	return rankUnused;
}

QString CraftInfo::getType() const {
	return type;
}

QString CraftInfo::getName() const {
	return name;
}



#ifndef CRAFTINFO_H
#define CRAFTINFO_H
#include <QString>
#include <QJsonObject>
class CraftInfo
{
public:
	CraftInfo();
	static CraftInfo fromJson(const QJsonObject& craftInfoObject);

	int getRank() const;
	int getMrank() const;
	bool isRankUnused() const;
	QString getType() const;
	QString getName() const;

private:
	QString name;
	QString type;
	bool rankUnused;
	int mrank;
	int rank;
};

#endif // CRAFTINFO_H
#include "dbmanager.h"
#include "logger.h"
#include <QSqlError>
#include <QDebug>
#include <QJsonDocument>

DbManager::DbManager(const QString& path, const QString connName, QObject* parent)
	: QObject(parent), m_db(QSqlDatabase::addDatabase("QSQLITE", connName))
{
	m_db.setDatabaseName(path);

	if (!m_db.open()) {
		LOG_ERROR(QString("Database connection error: %1").arg(m_db.lastError().text()));
	}
	else {
		LOG_INFO("Database connected successfully");
		prepareQueries();
		createTables();
	}
}

DbManager::~DbManager()
{
	if (m_db.isOpen()) {
		m_db.close();
	}
}

void DbManager::prepareQueries()
{
	// Replay table insert
	m_insertReplayQuery = QSqlQuery(m_db);
	m_insertReplayQuery.prepare(R"(
        INSERT OR IGNORE INTO Replay 
        (session_id, author_id, start_time, map, game_mode, difficulty, status, time_played)
        VALUES 
        (:session_id, :author_id, :start_time, :map, :game_mode, :difficulty, :status, :time_played)
    )");

	// Player table insert
	m_insertPlayerQuery = QSqlQuery(m_db);
	m_insertPlayerQuery.prepare(R"(
        INSERT OR REPLACE INTO Player 
        (player_id, username, squadron_tag, squadron_id, platform)
        VALUES 
        (:player_id, :username, :squadron_tag, :squadron_id, :platform)
    )");

	// PlayerReplayData table insert
	m_insertPlayerDataQuery = QSqlQuery(m_db);
	m_insertPlayerDataQuery.prepare(R"(
        INSERT OR IGNORE INTO PlayerReplayData 
        (session_id, player_id, air_kills, ground_kills, naval_kills, team_kills,
         ai_air_kills, ai_ground_kills, ai_naval_kills, assists, deaths, captured_zones,
         damage_to_zones, score, award_damage, missile_evades, team, squad_id, auto_squad, wait_time, lineup)
        VALUES 
        (:session_id, :player_id, :air_kills, :ground_kills, :naval_kills, :team_kills,
         :ai_air_kills, :ai_ground_kills, :ai_naval_kills, :assists, :deaths, :captured_zones,
         :damage_to_zones, :score, :award_damage, :missile_evades, :team, :squad_id, :auto_squad, :wait_time, :lineup)
    )");
}

void DbManager::createTables()
{
	QSqlQuery query(m_db);
	query.exec("PRAGMA journal_mode = WAL");
	query.exec("PRAGMA synchronous = NORMAL");

	const QStringList tableDefinitions = {
		R"(
            CREATE TABLE IF NOT EXISTS Player (
                player_id INTEGER PRIMARY KEY,
                username TEXT NOT NULL,
                squadron_tag TEXT,
                squadron_id INTEGER,
                platform TEXT NOT NULL
            )
        )",
		R"(
            CREATE TABLE IF NOT EXISTS Replay (
                session_id TEXT PRIMARY KEY,
                author_id INTEGER,
                start_time INTEGER,
                map TEXT,
                game_mode TEXT ,
                difficulty INTEGER,
                status TEXT,
                time_played REAL,
                FOREIGN KEY (author_id) REFERENCES Player(player_id) ON DELETE CASCADE
            )
        )",
		R"(
            CREATE TABLE IF NOT EXISTS PlayerReplayData (
                session_id TEXT NOT NULL,
                player_id INTEGER NOT NULL,
                air_kills INTEGER DEFAULT 0,
                ground_kills INTEGER DEFAULT 0,
                naval_kills INTEGER DEFAULT 0,
                team_kills INTEGER DEFAULT 0,
                ai_air_kills INTEGER DEFAULT 0,
                ai_ground_kills INTEGER DEFAULT 0,
                ai_naval_kills INTEGER DEFAULT 0,
                assists INTEGER DEFAULT 0,
                deaths INTEGER DEFAULT 0,
                captured_zones INTEGER DEFAULT 0,
                damage_to_zones INTEGER DEFAULT 0,
                score INTEGER DEFAULT 0,
                award_damage INTEGER DEFAULT 0,
                missile_evades INTEGER DEFAULT 0,
                team INTEGER DEFAULT 0,
                squad_id INTEGER DEFAULT 0,
				wait_time REAL NOT NULL DEFAULT 0,
                auto_squad INTEGER DEFAULT 0,
				lineup TEXT NOT NULL,
                PRIMARY KEY (session_id, player_id),
                FOREIGN KEY (player_id) REFERENCES Player(player_id) ON DELETE CASCADE,
                FOREIGN KEY (session_id) REFERENCES Replay(session_id) ON DELETE CASCADE
            )
        )"

	};

	for (const QString& tableSql : tableDefinitions) {
		if (!query.exec(tableSql)) {
			LOG_ERROR(QString("Table creation failed: %1").arg(query.lastError().text()));
		}
	}
}

bool DbManager::insertReplay(const Replay& replay)
{
	if (!m_db.transaction()) {
		LOG_ERROR(QString("Transaction start failed: %1").arg(m_db.lastError().text()));
		return false;
	}

	try {
		m_insertReplayQuery.bindValue(":session_id", replay.getSessionId());
		m_insertReplayQuery.bindValue(":author_id", replay.getAuthorUserId().toULongLong());
		m_insertReplayQuery.bindValue(":start_time", replay.getStartTime());
		m_insertReplayQuery.bindValue(":map", replay.getLevel());
		m_insertReplayQuery.bindValue(":game_mode", replay.getBattleType());
		m_insertReplayQuery.bindValue(":difficulty", static_cast<int>(replay.getDifficulty()));
		m_insertReplayQuery.bindValue(":status", replay.getStatus());
		m_insertReplayQuery.bindValue(":time_played", replay.getTimePlayed());

		if (!m_insertReplayQuery.exec()) {
			LOG_ERROR(QString("Replay insert failed: %1").arg(m_insertReplayQuery.lastError().text()));
			throw std::runtime_error("Replay insert failed");
		}

		const QList<QPair<Player, PlayerReplayData>> players = replay.getPlayers();
		for (const QPair<Player, PlayerReplayData>& player : players) {
			m_insertPlayerQuery.bindValue(":player_id", player.first.getUserId().toULongLong());
			m_insertPlayerQuery.bindValue(":username", player.first.getUsername());
			m_insertPlayerQuery.bindValue(":squadron_tag", player.first.getSquadronTag());
			m_insertPlayerQuery.bindValue(":squadron_id", player.first.getSquadronId());
			m_insertPlayerQuery.bindValue(":platform", player.first.getPlatform());

			if (!m_insertPlayerQuery.exec()) {
				throw std::runtime_error("Player insert failed");
			}

			m_insertPlayerDataQuery.bindValue(":session_id", replay.getSessionId());
			m_insertPlayerDataQuery.bindValue(":player_id", player.second.getUserId().toULongLong());
			m_insertPlayerDataQuery.bindValue(":air_kills", player.second.getKills());
			m_insertPlayerDataQuery.bindValue(":ground_kills", player.second.getGroundKills());
			m_insertPlayerDataQuery.bindValue(":naval_kills", player.second.getNavalKills());
			m_insertPlayerDataQuery.bindValue(":team_kills", player.second.getTeamKills());
			m_insertPlayerDataQuery.bindValue(":ai_air_kills", player.second.getAiKills());
			m_insertPlayerDataQuery.bindValue(":ai_ground_kills", player.second.getAiGroundKills());
			m_insertPlayerDataQuery.bindValue(":ai_naval_kills", player.second.getAiNavalKills());
			m_insertPlayerDataQuery.bindValue(":assists", player.second.getAssists());
			m_insertPlayerDataQuery.bindValue(":deaths", player.second.getDeaths());
			m_insertPlayerDataQuery.bindValue(":captured_zones", player.second.getCaptureZone());
			m_insertPlayerDataQuery.bindValue(":damage_to_zones", player.second.getDamageZone());
			m_insertPlayerDataQuery.bindValue(":score", player.second.getScore());
			m_insertPlayerDataQuery.bindValue(":award_damage", player.second.getAwardDamage());
			m_insertPlayerDataQuery.bindValue(":missile_evades", player.second.getMissileEvades());
			m_insertPlayerDataQuery.bindValue(":team", player.second.getTeam());
			m_insertPlayerDataQuery.bindValue(":squad_id", player.second.getSquad());
			m_insertPlayerDataQuery.bindValue(":auto_squad", player.second.getAutoSquad());
			m_insertPlayerDataQuery.bindValue(":wait_time", player.second.getWaitTime());
			QString lineup = player.second.getLineup().join(",");
			m_insertPlayerDataQuery.bindValue(":lineup", lineup);

			if (!m_insertPlayerDataQuery.exec()) {
				throw std::runtime_error("Player data insert failed");
			}
		}

		if (!m_db.commit()) {
			throw std::runtime_error("Commit failed");
		}
		return true;

	}
	catch (const std::exception& e) {
		m_db.rollback();
		LOG_ERROR(QString("Database error: %1").arg(e.what()));
		return false;
	}
}

QMap<QDate, QList<Replay>> DbManager::fetchReplaysGroupedByDate()
{
	QMap<QDate, QList<Replay>> replayMap;
	QSqlQuery query(m_db);

	query.prepare(R"(
        SELECT session_id, author_id, start_time, map, game_mode, 
               difficulty, status, time_played
        FROM Replay
        ORDER BY start_time DESC
    )");

	if (!query.exec()) {
		LOG_WARN(QString("Failed to fetch replays :%1").arg(query.lastError().text()));
		return replayMap;
	}

	while (query.next()) {
		Replay replay;

		replay.setSessionId(query.value("session_id").toString());
		replay.setAuthorUserId(QString::number(query.value("author_id").toULongLong()));
		replay.setStartTime(query.value("start_time").toLongLong());
		replay.setLevel(query.value("map").toString());
		replay.setBattleType(query.value("game_mode").toString());
		replay.setDifficulty(static_cast<Constants::Difficulty>(query.value("difficulty").toInt()));
		replay.setStatus(query.value("status").toString());
		replay.setTimePlayed(query.value("time_played").toFloat());

		QDate dateKey = QDateTime::fromSecsSinceEpoch(replay.getStartTime()).date();

		replayMap[dateKey].append(replay);
	}

	for (auto& replays : replayMap) {
		std::sort(replays.begin(), replays.end(), [](const Replay& a, const Replay& b) {
			return a.getStartTime() < b.getStartTime();
			});
	}

	return replayMap;
}

qint64 DbManager::getLatestReplay()
{
	QSqlQuery query("SELECT start_time FROM Replay ORDER BY start_time DESC LIMIT 1", m_db);
	if (query.exec() && query.next()) {
		return query.value(0).toLongLong();
	}
	return 0;
}


Replay DbManager::getReplayBySessionId(QString sessionId)
{
	QSqlQuery query(m_db);
	query.prepare(R"(SELECT * FROM Replay WHERE session_id = :session_id)");
	query.bindValue(":session_id", sessionId);

	if (!query.exec() || !query.next()) {
		LOG_WARN(QString("Failed to fetch replay with session_id: %1 %2").arg(sessionId, query.lastError().text()));
		return Replay();
	}

	Replay replay;
	replay.setSessionId(query.value("session_id").toString());
	replay.setAuthorUserId(QString::number(query.value("author_id").toULongLong()));
	replay.setStartTime(query.value("start_time").toLongLong());
	replay.setLevel(query.value("map").toString());
	replay.setBattleType(query.value("game_mode").toString());
	replay.setDifficulty(static_cast<Constants::Difficulty>(query.value("difficulty").toInt()));
	replay.setStatus(query.value("status").toString());
	replay.setTimePlayed(query.value("time_played").toFloat());

	query.prepare(R"(SELECT * FROM PlayerReplayData JOIN Player ON PlayerReplayData.player_id=Player.player_id WHERE session_id = :session_id)");
	query.bindValue(":session_id", sessionId);

	if (!query.exec() || !query.next()) {
		LOG_WARN(QString("Failed to fetch playerReplay with session_id: %1 %2").arg(sessionId, query.lastError().text()));
		return Replay();
	}

	QList<QPair<Player, PlayerReplayData>> players;
	while (query.next()) {
		Player player;
		PlayerReplayData playerData;

		player.setUserId(query.value("player_id").toString());
		player.setUsername(query.value("username").toString());
		player.setSquadronTag(query.value("squadron_tag").toString());
		player.setSquadronId(query.value("squadron_id").toString());
		player.setPlatform(query.value("platform").toString());

		playerData.setUserId(query.value("player_id").toString());
		playerData.setKills(query.value("air_kills").toInt());
		playerData.setGroundKills(query.value("ground_kills").toInt());
		playerData.setNavalKills(query.value("naval_kills").toInt());
		playerData.setTeamKills(query.value("team_kills").toInt());
		playerData.setAiKills(query.value("ai_air_kills").toInt());
		playerData.setAiGroundKills(query.value("ai_ground_kills").toInt());
		playerData.setAiNavalKills(query.value("ai_naval_kills").toInt());
		playerData.setAssists(query.value("assists").toInt());
		playerData.setDeaths(query.value("deaths").toInt());
		playerData.setCaptureZone(query.value("captured_zones").toInt());
		playerData.setDamageZone(query.value("damage_to_zones").toInt());
		playerData.setScore(query.value("score").toInt());
		playerData.setAwardDamage(query.value("award_damage").toInt());
		playerData.setMissileEvades(query.value("missile_evades").toInt());
		playerData.setTeam(query.value("team").toInt());
		playerData.setSquad(query.value("squad_id").toInt());
		playerData.setAutoSquad(query.value("auto_squad").toBool());
		playerData.setLineup(query.value("lineup").toString().split(","));
		playerData.setWaitTime(query.value("wait_time").toDouble());

		players.append(QPair<Player, PlayerReplayData>(player, playerData));
	}
	replay.setPlayers(players);

	return replay;
}

bool DbManager::deleteReplayBySessionId(QString sessionId) {
	QSqlQuery query(m_db);
	query.prepare(R"(DELETE FROM PlayerReplayData WHERE session_id = :session_id)");
	query.bindValue(":session_id", sessionId);
	if (!query.exec()) {
		LOG_WARN(QString("Failed to delete replay with session_id: %1 %2").arg(sessionId, query.lastError().text()));
		return false;
	}
	deleteDanglingRecords();
	return true;
}

int DbManager::deleteDanglingRecords() {
	QSqlQuery query(m_db);
	query.prepare(R"(
		DELETE FROM Player WHERE player_id NOT IN (SELECT DISTINCT player_id FROM PlayerReplayData)
	)");
	if (!query.exec()) {
		LOG_WARN(QString("Failed to delete dangling records:%1").arg(query.lastError().text()));
		return 0;
	}
	query.prepare(R"(
		DELETE FROM Replay WHERE session_id NOT IN (SELECT DISTINCT session_id FROM PlayerReplayData)
	)");
	if (!query.exec()) {
		LOG_WARN(QString("Failed to delete dangling records:%1").arg(query.lastError().text()));
		return 0;
	}
	return query.numRowsAffected();
}#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDateTime>
#include "replay.h"
#include "player.h"
#include "utils.h"

class DbManager : public QObject
{
    Q_OBJECT
public:
    explicit DbManager(const QString& path, const QString connName, QObject* parent = nullptr);
    ~DbManager();

    void createTables();
    bool insertReplay(const Replay& replay);
    qint64 getLatestReplay();
    Replay getReplayBySessionId(QString sessionId);
    bool deleteReplayBySessionId(QString sessionId);
    int deleteDanglingRecords();
    QMap<QDate, QList<Replay>> fetchReplaysGroupedByDate();


private:
    void prepareQueries();
    void createIndexes();


    QSqlDatabase m_db;
    QSqlQuery m_insertReplayQuery;
    QSqlQuery m_insertPlayerQuery;
    QSqlQuery m_insertPlayerCraftQuery;
    QSqlQuery m_insertPlayerDataQuery;
};

#endif // DBMANAGER_H#include "discordworker.h"
#include <QMetaEnum>
DiscordWorker::DiscordWorker(QObject* parent) : QObject(parent) {
	updateTimer = new QTimer(this);
	if (discord::Core::Create(1338259195455344650, DiscordCreateFlags_NoRequireDiscord, &core) != discord::Result::Ok) {
		QThread::currentThread()->quit();
		return;
	}
	if (core) {
		connect(updateTimer, &QTimer::timeout, this, [this]() mutable {
			discord::Result result = core->RunCallbacks();
			if (result != discord::Result::Ok) {
				qDebug() << "From connect: " << static_cast<int>(result);

				QThread::currentThread()->quit();
				return;
			}});
	}
}

DiscordWorker::~DiscordWorker() {
	stop();
}

void DiscordWorker::start() {
	updateTimer->start(5000);
}

void DiscordWorker::stop() {
	if (QThread::currentThread() != this->thread()) {
		QMetaObject::invokeMethod(this, "stop", Qt::QueuedConnection);
		return;
	}
	if (updateTimer->isActive()) {
		updateTimer->stop();
	}
}

void DiscordWorker::updateActivity(const QString& state, const QString& details, const QString& logo, const QDateTime& epochStartTime, const QString& largeText) {
	if (!core) return;
	QDateTime validStartTime = epochStartTime.isValid() ? epochStartTime : QDateTime::currentDateTime();
	discord::Activity activity{};
	activity.SetName("War Thunder");
	activity.GetParty().GetSize().SetCurrentSize(0);
	activity.GetParty().GetSize().SetMaxSize(0);
	activity.SetState(state.toStdString().c_str());
	activity.SetDetails(details.toStdString().c_str());
	activity.GetTimestamps().SetStart(validStartTime.toSecsSinceEpoch());
	auto& assets = activity.GetAssets();
	assets.SetLargeImage(logo.toStdString().c_str());
	assets.SetLargeText(largeText.toStdString().c_str());

	core->ActivityManager().UpdateActivity(activity, [](discord::Result result) {
		if (static_cast<int>(result) != 0) {
			qDebug() << "Discord activity updated, result:" << static_cast<int>(result);
		}
		});

	discord::Result result = core->RunCallbacks();
	if (result != discord::Result::Ok) {
		qDebug() << "From updateactivity: " << static_cast<int>(result);
		QThread::currentThread()->quit();
		return;
	};
}
#ifndef DISCORDWORKER_H
#define DISCORDWORKER_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QThread>
#include <qdatetime.h>
#include "discord-files/cpp/discord.h"

class DiscordWorker : public QObject {
	Q_OBJECT

public:
	explicit DiscordWorker(QObject* parent = nullptr);
	~DiscordWorker();

public slots:
	void start();                  // Called to start loop/timer
	void stop();                   // Graceful shutdown
    void updateActivity(const QString& state, const QString& details, const QString& logo, const QDateTime& epochStartTime = QDateTime(), const QString& largeText = QString());

private:
	QTimer* updateTimer = nullptr;
	discord::Core* core{};
	discord::Activity activity{};
};
#endif // DISCORDWORKER_H
#include <QDateTime>
#include <QFileInfo>
#include "logger.h"

Logger& Logger::instance() {
	static Logger _instance;
	return _instance;
}

Logger::Logger(QObject* parent) : QObject(parent), m_out(&m_file) {}

Logger::~Logger() {
	if (m_file.isOpen())
		m_file.close();
}

bool Logger::init(const QString& filePath) {
	m_file.setFileName(filePath);
	if (!m_file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
		return false;
	m_file.close();
	if (!m_file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
		return false;
	return true;
}

void Logger::write(const QString& level, const QString& msg, const char* funcName, QObject* sender, const char* filePath, int line) {
	QMutexLocker locker(&m_mutex);

	QString ts = QDateTime::currentDateTime().toString(Qt::ISODate);

	// strip path to just filename.cpp
	QFileInfo fi(QString::fromUtf8(filePath));
	QString fileName = fi.fileName();

	QString cls = sender ? sender->metaObject()->className() : QStringLiteral("Global");

	// format:
	// 2025-05-14T21:26:55 [INFO] (ClassName::function @ filename.cpp:187) My message
	m_out << ts << " [" << level << "] " << "(" << cls << "::" << funcName << " @ " << fileName << ":" << line << ") " << msg << "\n";
	m_out.flush();
}

void Logger::info(const QString& msg, const char* funcName, QObject* sender, const char* filePath, int line) {
	instance().write("INFO", msg, funcName, sender, filePath, line);
}

void Logger::warning(const QString& msg, const char* funcName, QObject* sender, const char* filePath, int line) {
	instance().write("WARN", msg, funcName, sender, filePath, line);
}

void Logger::error(const QString& msg, const char* funcName, QObject* sender, const char* filePath, int line) {
	instance().write("ERROR", msg, funcName, sender, filePath, line);
}﻿#ifndef LOGGER_H
#define LOGGER_H

#include <QFile>
#include <QMutex>
#include <QObject>
#include <QTextStream>

class Logger : public QObject {
	Q_OBJECT
public:
	static Logger& instance();
	bool init(const QString& filePath);

	// full write API: pass level, message, function-name, sender-object, source-file, and line
	void write(const QString& level, const QString& msg, const char* funcName, QObject* sender, const char* filePath, int line);

	static void info(const QString& msg, const char* funcName, QObject* sender, const char* filePath, int line);
	static void warning(const QString& msg, const char* funcName, QObject* sender, const char* filePath, int line);
	static void error(const QString& msg, const char* funcName, QObject* sender, const char* filePath, int line);

private:
	explicit Logger(QObject* parent = nullptr);
	~Logger();

	QFile m_file;
	QTextStream m_out;
	QMutex m_mutex;
};

// ——— Macros ———

// inside any QObject-derived class
#define LOG_INFO(msg) Logger::info(msg, __FUNCTION__, this, __FILE__, __LINE__)
#define LOG_WARN(msg) Logger::warning(msg, __FUNCTION__, this, __FILE__, __LINE__)
#define LOG_ERROR(msg) Logger::error(msg, __FUNCTION__, this, __FILE__, __LINE__)

// from global (non-QObject) code, or lambdas where you have no 'this'
#define LOG_INFO_GLOBAL(msg) Logger::info(msg, __FUNCTION__, nullptr, __FILE__, __LINE__)
#define LOG_WARN_GLOBAL(msg) Logger::warning(msg, __FUNCTION__, nullptr, __FILE__, __LINE__)
#define LOG_ERROR_GLOBAL(msg) Logger::error(msg, __FUNCTION__, nullptr, __FILE__, __LINE__)

#endif  // LOGGER_H#include "player.h"

Player::Player(){}

Player Player::fromJson(const QJsonObject& playerInfoObject) {
	Player player;

	auto getString = [&playerInfoObject](const QString& key, const QString& defaultValue = "") {
		return playerInfoObject.contains(key) && playerInfoObject[key].isString() ? playerInfoObject[key].toString() : defaultValue;
	};

	auto getIntAsString = [&playerInfoObject](const QString& key, const QString& defaultValue = "") {
		return playerInfoObject.contains(key) && playerInfoObject[key].isDouble() ? QString::number(playerInfoObject[key].toInt()) : defaultValue;
	};

	player.m_userId = getIntAsString("id");
	player.m_username = getString("name");

	player.m_squadronId = getIntAsString("clanId");
	if (player.m_squadronId == "-1") {
		player.m_squadronId = QString(); // Set to empty string instead of NULL
	}

	player.m_squadronTag = getString("clanTag");
	if (player.m_squadronTag.isEmpty()) {
		player.m_squadronTag = QString(); // Set to empty string instead of NULL
	}

	player.m_platform = getString("platform");

	return player;
}

QString Player::getUserId() const { return m_userId; }
QString Player::getUsername() const { return m_username; }
QString Player::getSquadronId() const { return m_squadronId; }
QString Player::getSquadronTag() const { return m_squadronTag; }
QString Player::getPlatform() const { return m_platform; }

void Player::setUserId(QString userId)
{
	m_userId = userId;
}

void Player::setUsername(QString username)
{
	m_username = username;
}

void Player::setSquadronId(QString squadronId)
{
	m_squadronId = squadronId;
}

void Player::setSquadronTag(QString squadronTag)
{
	m_squadronTag = squadronTag;
}

void Player::setPlatform(QString platform)
{
	m_platform = platform;
}
#ifndef PLAYERINFO_H
#define PLAYERINFO_H
#include <QString>
#include <QJsonObject>
class Player
{
public:
	Player();
	static Player fromJson(const QJsonObject& playerInfoObject);

	QString getUserId() const;
	QString getUsername() const;
	QString getSquadronId() const;
	QString getSquadronTag() const;
	QString getPlatform() const;

	void setUserId(QString userId);
	void setUsername(QString username);
	void setSquadronId(QString squadronId);
	void setSquadronTag(QString squadronTag);
	void setPlatform(QString platform);

	bool operator<(const Player& other) const {
		return this->m_userId < other.m_userId;
	}
	
private:
	QString m_userId;
	QString m_username;
	QString m_squadronId;
	QString m_squadronTag;
	QString m_platform;
};

#endif // PLAYERINFO_H
#include "playerreplaydata.h"

PlayerReplayData::PlayerReplayData() {}

PlayerReplayData PlayerReplayData::fromJson(const QJsonObject& json) {
	PlayerReplayData playerReplayData;

	auto getInt = [&json](const QString& key, int defaultValue = 0) {
		return json.contains(key) && json[key].isDouble() ? json[key].toInt() : defaultValue;
		};

	auto getBool = [&json](const QString& key, bool defaultValue = false) {
		return json.contains(key) && json[key].isBool() ? json[key].toBool() : defaultValue;
		};

	auto getString = [&json](const QString& key, const QString& defaultValue = "") {
		return json.contains(key) && json[key].isString() ? json[key].toString() : defaultValue;
		};

	playerReplayData.m_userId = getString("userId");
	playerReplayData.m_squad = getInt("squadId");
	playerReplayData.m_autosquad = getBool("autoSquad");
	playerReplayData.m_team = getInt("team");
	playerReplayData.m_kills = getInt("kills");
	playerReplayData.m_groundKills = getInt("groundKills");
	playerReplayData.m_navalKills = getInt("navalKills");
	playerReplayData.m_teamKills = getInt("teamKills");
	playerReplayData.m_aiKills = getInt("aiKills");
	playerReplayData.m_aiGroundKills = getInt("aiGroundKills");
	playerReplayData.m_aiNavalKills = getInt("aiNavalKills");
	playerReplayData.m_assists = getInt("assists");
	playerReplayData.m_deaths = getInt("deaths");
	playerReplayData.m_captureZone = getInt("captureZone");
	playerReplayData.m_damageZone = getInt("damageZone");
	playerReplayData.m_score = getInt("score");
	playerReplayData.m_awardDamage = getInt("awardDamage");
	playerReplayData.m_missileEvades = getInt("missileEvades");

	return playerReplayData;
}

QString PlayerReplayData::getUserId() const { return m_userId; }
int PlayerReplayData::getSquad() const { return m_squad; }
bool PlayerReplayData::getAutoSquad() const { return m_autosquad; }
int PlayerReplayData::getTeam() const { return m_team; }
float PlayerReplayData::getWaitTime() const { return m_waitTime; }
int PlayerReplayData::getKills() const { return m_kills; }
int PlayerReplayData::getGroundKills() const { return m_groundKills; }
int PlayerReplayData::getNavalKills() const { return m_navalKills; }
int PlayerReplayData::getTeamKills() const { return m_teamKills; }
int PlayerReplayData::getAiKills() const { return m_aiKills; }
int PlayerReplayData::getAiGroundKills() const { return m_aiGroundKills; }
int PlayerReplayData::getAiNavalKills() const { return m_aiNavalKills; }
int PlayerReplayData::getAssists() const { return m_assists; }
int PlayerReplayData::getDeaths() const { return m_deaths; }
int PlayerReplayData::getCaptureZone() const { return m_captureZone; }
int PlayerReplayData::getDamageZone() const { return m_damageZone; }
int PlayerReplayData::getScore() const { return m_score; }
int PlayerReplayData::getAwardDamage() const { return m_awardDamage; }
int PlayerReplayData::getMissileEvades() const { return m_missileEvades; }
QList<QString> PlayerReplayData::getLineup() const { return m_lineup; }

void PlayerReplayData::setUserId(QString userId)
{
	m_userId = userId;
}

void PlayerReplayData::setSquad(int squad) { this->m_squad = squad; }
void PlayerReplayData::setAutoSquad(bool autosquad) { this->m_autosquad = autosquad; }
void PlayerReplayData::setTeam(int team) { this->m_team = team; }
void PlayerReplayData::setKills(int kills) { this->m_kills = kills; }
void PlayerReplayData::setGroundKills(int groundKills) { this->m_groundKills = groundKills; }
void PlayerReplayData::setNavalKills(int navalKills) { this->m_navalKills = navalKills; }
void PlayerReplayData::setTeamKills(int teamKills) { this->m_teamKills = teamKills; }
void PlayerReplayData::setAiKills(int aiKills) { this->m_aiKills = aiKills; }
void PlayerReplayData::setAiGroundKills(int aiGroundKills) { this->m_aiGroundKills = aiGroundKills; }
void PlayerReplayData::setAiNavalKills(int aiNavalKills) { this->m_aiNavalKills = aiNavalKills; }
void PlayerReplayData::setAssists(int assists) {
	this->m_assists = assists;
}
void PlayerReplayData::setDeaths(int deaths) { this->m_deaths = deaths; }
void PlayerReplayData::setCaptureZone(int captureZone) { this->m_captureZone = captureZone; }
void PlayerReplayData::setDamageZone(int damageZone) { this->m_damageZone = damageZone; }
void PlayerReplayData::setScore(int score) { this->m_score = score; }
void PlayerReplayData::setAwardDamage(int awardDamage) { this->m_awardDamage = awardDamage; }
void PlayerReplayData::setMissileEvades(int missileEvades) { this->m_missileEvades = missileEvades; }



void PlayerReplayData::setWaitTime(float waitTime) { this->m_waitTime = waitTime; }
void PlayerReplayData::setLineup(QList<QString> lineup) { this->m_lineup = lineup; }#ifndef PLAYERREPLAYDATA_H
#define PLAYERREPLAYDATA_H

#include <QString>
#include <QJsonObject>
#include <QList>

class PlayerReplayData {
public:
	PlayerReplayData();

	static PlayerReplayData fromJson(const QJsonObject& json);

	QString getUserId() const;
	int getSquad() const;
	bool getAutoSquad() const;
	int getTeam() const;
	float getWaitTime() const;
	int getKills() const;
	int getGroundKills() const;
	int getNavalKills() const;
	int getTeamKills() const;
	int getAiKills() const;
	int getAiGroundKills() const;
	int getAiNavalKills() const;
	int getAssists() const;
	int getDeaths() const;
	int getCaptureZone() const;
	int getDamageZone() const;
	int getScore() const;
	int getAwardDamage() const;
	int getMissileEvades() const;
	QList<QString> getLineup() const;

	void setUserId(QString userId);
	void setSquad(int squad);
	void setAutoSquad(bool autosquad);
	void setTeam(int team);
	void setWaitTime(float waitTime);
	void setKills(int kills);
	void setGroundKills(int groundKills);
	void setNavalKills(int navalKills);
	void setTeamKills(int teamKills);
	void setAiKills(int aiKills);
	void setAiGroundKills(int aiGroundKills);
	void setAiNavalKills(int aiNavalKills);
	void setAssists(int assists);
	void setDeaths(int deaths);
	void setCaptureZone(int captureZone);
	void setDamageZone(int damageZone);
	void setScore(int score);
	void setAwardDamage(int awardDamage);
	void setMissileEvades(int missileEvades);
	void setLineup(QList<QString> lineup);

private:
	QString m_userId;
	int m_squad;
	bool m_autosquad;
	int m_team;
	float m_waitTime;
	int m_kills;
	int m_groundKills;
	int m_navalKills;
	int m_teamKills;
	int m_aiKills;
	int m_aiGroundKills;
	int m_aiNavalKills;
	int m_assists;
	int m_deaths;
	int m_captureZone;
	int m_damageZone;
	int m_score;
	int m_awardDamage;
	int m_missileEvades;
	QList<QString> m_lineup;
};

#endif // PLAYERREPLAYDATA_H#include "position.h"
#include <stdexcept>

Position::Position(double x, double y, const QString& color, const QString& type, const QString& icon, qint64 timestamp)
	: m_x(x), m_y(y), m_color(color), m_type(type), m_icon(icon), m_timestamp(timestamp) {
	if (x < 0 || x > 1) {
		throw std::invalid_argument("x must be between 0 and 1");
	}
	if (y < 0 || y > 1) {
		throw std::invalid_argument("y must be between 0 and 1");
	}
}

double Position::x() const {
	return m_x;
}

double Position::y() const {
	return m_y;
}

QString Position::color() const {
	return m_color;
}

QString Position::type() const {
	return m_type;
}

QString Position::icon() const {
	return m_icon;
}

qint64 Position::timestamp() const {
	return m_timestamp;
}

bool Position::isCaptureZone() const {
	return m_type.compare("capture_zone", Qt::CaseInsensitive) == 0;
}

bool Position::isRespawnBaseTank() const {
	return m_type.compare("respawn_base_tank", Qt::CaseInsensitive) == 0;
}

bool Position::isPlayer() const {
	return m_icon.compare("Player", Qt::CaseInsensitive) == 0;
}

bool Position::isAirfield() const {
	return m_type.compare("airfield", Qt::CaseInsensitive) == 0;
}

bool Position::isAircraft() const {
	return m_type.compare("aircraft", Qt::CaseInsensitive) == 0;
}

bool Position::isRespawnBaseFighter() const {
	return m_type.compare("respawn_base_fighter", Qt::CaseInsensitive) == 0;
}

bool Position::isValid() const {
	return m_x >= 0 && m_x <= 1 && m_y >= 0 && m_y <= 1;
}#ifndef POSITION_H
#define POSITION_H

#include <QString>

class Position {
public:
	Position(double x = -1, double y = -1, const QString& color = "#FFFFFF", const QString& type = "unknown", const QString& icon = "unknown", qint64 timestamp = 0);

	double x() const;
	double y() const;
	QString color() const;
	QString type() const;
	QString icon() const;
	qint64 timestamp() const;

	bool isCaptureZone() const;
	bool isRespawnBaseTank() const;
	bool isPlayer() const;
	bool isAirfield() const;
	bool isAircraft() const;
	bool isRespawnBaseFighter() const;

	bool isValid() const;

private:
	double m_x;
	double m_y;
	QString m_color;
	QString m_type;
	QString m_icon;
	qint64 m_timestamp;
};

#endif // POSITION_H#include "replay.h"
#include "logger.h"
#include <QBuffer>
#include <QByteArray>
#include <QCoreApplication>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QProcess>

const QByteArray Replay::MAGIC = QByteArray::fromHex("e5ac0010");
Replay::~Replay()
{
}


Replay::Replay(const QByteArray& buffer) {
	QDataStream stream(buffer);
	stream.setByteOrder(QDataStream::LittleEndian);

	QByteArray magic(4, 0);
	stream.readRawData(magic.data(), 4);
	if (magic != MAGIC) {
		throw std::runtime_error("Invalid magic number, maybe not a replay file?");
	}

	stream >> m_version;
	m_level = readString(stream, 128).replace("levels/", "").replace(".bin", "");
	m_levelSettings = readString(stream, 260);
	m_battleType = readString(stream, 128);
	m_environment = readString(stream, 128);
	m_visibility = readString(stream, 32);
	stream >> m_rezOffset;
	quint8 difficultyTemp;
	stream >> difficultyTemp;
	difficultyTemp &= 0x0F;
	m_difficulty = static_cast<Constants::Difficulty>(difficultyTemp);
	stream.skipRawData(35); // Skip 35 bytes
	stream >> m_sessionType;
	stream.skipRawData(7); // Skip 7 bytes

	quint64 sessionIdInt;
	stream >> sessionIdInt;
	m_sessionId = QString::number(sessionIdInt, 16);

	stream.skipRawData(4); // Skip 4 bytes
	stream >> m_mSetSize;
	stream.skipRawData(32); // Skip 32 bytes
	m_locName = readString(stream, 128);
	stream >> m_startTime >> m_timeLimit >> m_scoreLimit;
	stream.skipRawData(48); // Skip 48 bytes
	m_battleClass = readString(stream, 128);
	m_battleKillStreak = readString(stream, 128);

	try {
		auto results = unpackResults(m_rezOffset, buffer);
		parseResults(results);
	}
	catch (const std::exception& e) {
		LOG_WARN_GLOBAL(QString("Error unpacking results: %1").arg(e.what()));
	}
}

Replay::Replay()
{
}

Replay Replay::fromFile(const QString& filePath) {
	QFile file(filePath);
	if (!file.open(QIODevice::ReadOnly)) {
		throw std::runtime_error("Failed to open file");
	}

	QByteArray fileContent = file.readAll();
	return Replay(fileContent);
}

QString Replay::readString(QDataStream& stream, int length) {
	QByteArray bytes(length, 0);
	stream.readRawData(bytes.data(), length);

	int nullIndex = bytes.indexOf('\0');
	if (nullIndex != -1) {
		bytes.truncate(nullIndex);
	}

	return QString::fromUtf8(bytes);
}

QJsonObject Replay::unpackResults(int offset, const QByteArray& buffer) {
	QByteArray dataAfterRez = buffer.mid(offset);

	QProcess process;
	QString exe = QCoreApplication::applicationDirPath() + "/wt_ext_cli";
#ifdef Q_OS_WIN
	exe += ".exe";
#endif
	QStringList args{ "--unpack_raw_blk", "--stdout", "--stdin", "--format", "Json" };

	process.start(exe, args);
	if (!process.waitForStarted(3000)) {
		LOG_ERROR_GLOBAL(QString("Failed to start process: %1 %2").arg(process.errorString(), process.errorString()));
		throw std::runtime_error("Failed to start wt_ext_cli");
	}

	process.write(dataAfterRez);
	process.closeWriteChannel();

	if (!process.waitForFinished()) {
		throw std::runtime_error("Process did not finish");
	}

	QByteArray output = process.readAllStandardOutput();
	QJsonDocument jsonDoc = QJsonDocument::fromJson(output);
	if (jsonDoc.isNull() || !jsonDoc.isObject()) {
		throw std::runtime_error("Invalid JSON output");
	}

	return jsonDoc.object();
}

void Replay::parseResults(const QJsonObject& results) {
	this->m_status = results.value("status").toString("left");
	this->m_timePlayed = results.value("timePlayed").toDouble();
	this->m_authorUserId = results.value("authorUserId").toString();
	this->m_author = results.value("author").toString();

	if (this->m_authorUserId == "" || this->m_author == "") {
		this->m_authorUserId = "-1";
		this->m_author = "server";
	}

	QJsonArray playersArray = results.value("player").toArray();
	QJsonObject uiScriptsData = results.value("uiScriptsData").toObject();
	QJsonObject playersInfoObject = uiScriptsData.value("playersInfo").toObject();

	for (const auto& playerElement : playersArray) {
		QJsonObject playerObject = playerElement.toObject();
		for (auto it = playersInfoObject.begin(); it != playersInfoObject.end(); ++it) {
			QJsonObject playerInfoObject = it.value().toObject();
			if (playerInfoObject.value("id").toInteger() == playerObject.value("userId").toString().toULongLong()) {
				Player p = Player::fromJson(playerInfoObject);
				PlayerReplayData prd = PlayerReplayData::fromJson(playerObject);

				prd.setWaitTime(playerInfoObject.value("wait_time").toDouble());
				QJsonObject crafts = playerInfoObject.value("crafts").toObject();
				QList<QString> lineup;
				for (auto it1 = crafts.constBegin(); it1 != crafts.constEnd(); ++it1) {
					lineup.append(it1.value().toString());
				}
				prd.setLineup(lineup);
				QPair<Player, PlayerReplayData> pPair(p, prd);
				this->m_players.append(pPair);
				break;
			}
		}
	}
}

int Replay::getVersion() const { return m_version; }
QString Replay::getSessionId() const { return m_sessionId; }
QString Replay::getLevel() const { return m_level; }
QString Replay::getLevelSettings() const { return m_levelSettings; }
QString Replay::getBattleType() const { return m_battleType; }
QString Replay::getEnvironment() const { return m_environment; }
QString Replay::getVisibility() const { return m_visibility; }
int Replay::getRezOffset() const { return m_rezOffset; }
Constants::Difficulty Replay::getDifficulty() const { return m_difficulty; }
quint8 Replay::getSessionType() const { return m_sessionType; }
int Replay::getSetSize() const { return m_mSetSize; }
QString Replay::getLocName() const { return m_locName; }
int Replay::getStartTime() const { return m_startTime; }
int Replay::getTimeLimit() const { return m_timeLimit; }
int Replay::getScoreLimit() const { return m_scoreLimit; }
QString Replay::getBattleClass() const { return m_battleClass; }
QString Replay::getBattleKillStreak() const { return m_battleKillStreak; }
QString Replay::getStatus() const { return m_status; }
double Replay::getTimePlayed() const { return m_timePlayed; }
QString Replay::getAuthorUserId() const { return m_authorUserId; }
QString Replay::getAuthor() const { return m_author; }
QList<QPair<Player, PlayerReplayData>> Replay::getPlayers() const { return m_players; }

void Replay::setSessionId(QString sessionId)
{
	this->m_sessionId = sessionId;
}

void Replay::setAuthorUserId(QString authorUserId)
{
	this->m_authorUserId = authorUserId;
}

void Replay::setStartTime(int startTime)
{
	this->m_startTime = startTime;
}

void Replay::setLevel(QString level)
{
	this->m_level = level;
}

void Replay::setBattleType(QString battleType)
{
	this->m_battleType = battleType;
}

void Replay::setDifficulty(Constants::Difficulty difficulty)
{
	this->m_difficulty = difficulty;
}

void Replay::setStatus(QString status)
{
	this->m_status = status;
}

void Replay::setTimePlayed(double timePlayed)
{
	this->m_timePlayed = timePlayed;
}

void Replay::setPlayers(QList<QPair<Player, PlayerReplayData>> players)
{
	this->m_players = players;
}
#ifndef REPLAY_H
#define REPLAY_H

#include "constants.cpp"
#include "player.h"
#include "playerreplaydata.h"
#include <QByteArray>
#include <QJsonObject>
#include <QList>
#include <QString>
#include <QPair>

class Replay {
public:
	explicit Replay(const QByteArray& buffer);
	Replay();
	~Replay();

	static Replay fromFile(const QString& filePath);

	int getVersion() const;
	QString getSessionId() const;
	QString getLevel() const;
	QString getLevelSettings() const;
	QString getBattleType() const;
	QString getEnvironment() const;
	QString getVisibility() const;
	int getRezOffset() const;
	Constants::Difficulty getDifficulty() const;
	quint8 getSessionType() const;
	int getSetSize() const;
	QString getLocName() const;
	int getStartTime() const;
	int getTimeLimit() const;
	int getScoreLimit() const;
	QString getBattleClass() const;
	QString getBattleKillStreak() const;
	QString getStatus() const;
	double getTimePlayed() const;
	QString getAuthorUserId() const;
	QString getAuthor() const;
	QList<QPair<Player, PlayerReplayData>> getPlayers() const;

	void setSessionId(QString sessionId);
	void setAuthorUserId(QString authorUserId);
	void setStartTime(int startTime);
	void setLevel(QString level);
	void setBattleType(QString battleType);
	void setDifficulty(Constants::Difficulty difficulty);
	void setStatus(QString status);
	void setTimePlayed(double timePlayed);
	void setPlayers(QList<QPair<Player, PlayerReplayData>> players);

private:
	static const QByteArray MAGIC;
	int m_version;
	QString m_sessionId;
	QString m_level;
	QString m_levelSettings;
	QString m_battleType;
	QString m_environment;
	QString m_visibility;
	int m_rezOffset;
	Constants::Difficulty m_difficulty;
	quint8 m_sessionType;
	int m_mSetSize;
	QString m_locName;
	int m_startTime;
	int m_timeLimit;
	int m_scoreLimit;
	QString m_battleClass;
	QString m_battleKillStreak;
	QString m_status;
	double m_timePlayed;
	QString m_authorUserId;
	QString m_author;
	QList<QPair<Player, PlayerReplayData>> m_players;

	QString readString(QDataStream& stream, int length);
	QJsonObject unpackResults(int rezOffset, const QByteArray& buffer);
	void parseResults(const QJsonObject& results);
	void processMissingData(QList<PlayerReplayData>& playerReplayDataList, QJsonArray playersArray, QList<Player>& playerList, QJsonObject& playersInfoObject);
};

#endif // REPLAY_H
#include "replayloaderworker.h"
#include "logger.h"

ReplayLoaderWorker::ReplayLoaderWorker(const QString& folderPath,
	const QString& dbFilePath,
	QObject* parent)
	: QObject(parent),
	m_folderPath(folderPath),
	m_dbFilePath(dbFilePath)
{
}

void ReplayLoaderWorker::loadReplays() {
	DbManager localDbManager(m_dbFilePath, "replayloader");
	localDbManager.createTables();
	localDbManager.deleteDanglingRecords();

	qint64 latestReplayEpoch = localDbManager.getLatestReplay();

	QDir dir(m_folderPath);
	dir.setFilter(QDir::Files | QDir::NoSymLinks);
	dir.setNameFilters({ "*.wrpl" });
	QFileInfoList fileInfoList = dir.entryInfoList();

	int total = fileInfoList.size();
	int count = 0;

	for (const QFileInfo& fileInfo : fileInfoList) {
		if (fileInfo.birthTime().toSecsSinceEpoch() <= latestReplayEpoch) {
			++count;
			emit progressUpdated(total > 0 ? static_cast<int>(100.0 * count / total) : 100);
			continue;
		}
		QString filePath = fileInfo.absoluteFilePath();
		try {
			Replay rep = Replay::fromFile(filePath);
			localDbManager.insertReplay(rep);
		}
		catch (const std::exception& e) {
			LOG_WARN(QString("Error loading replay: %1").arg(e.what()));
		}
		++count;
		emit progressUpdated(total > 0 ? static_cast<int>(100.0 * count / total) : 100);
	}
	emit finished();
}#include <QObject>
#include <QDir>
#include <QFileInfo>
#include <QThread>
#include <QSettings>
#include <QStackedWidget>
#include "dbmanager.h"

class ReplayLoaderWorker : public QObject {
	Q_OBJECT
public:
	explicit ReplayLoaderWorker(const QString& folderPath, const QString& dbFilePath, QObject* parent = nullptr);

public slots:
	void loadReplays();

signals:
	void progressUpdated(int progress);
	void finished();

private:
	QString m_folderPath;
	QString m_dbFilePath;
};bitfield difficulty
{
    unsigned  unk_nib : 4;
    unsigned  difficulty : 4;
};

struct ReplayHeader {
    u32 magic;
    u32 version;
    char level[128];
    char levelSettings[260];
    char battleType[128];
    char environment[128];
    char visibility[32];
    u32 rezOffset;
    difficulty diff;
    padding[35];
    u32 sessionType;
    padding[4];
    u64 sessionIdHex;
    padding[4];
    u32 mSetSize;
    padding[32];
    char locName[128];
    u32 startTime;
    u32 timeLimit;
    u32 scoreLimit;
    padding[48];
    char battleClass[128];
    char battleKillStreak[128];
};

ReplayHeader repHeader @ 0x0 [[name("Header")]];#include "utils.h"
#include "version.h"
#include "logger.h"

#ifdef _MSC_VER
#include <intrin.h>
static inline int popcount32(unsigned int x) { return __popcnt(x); }
#else
static inline int popcount32(unsigned int x) { return __builtin_popcount(x); }
#endif

void Utils::checkAppVersion() {
	QUrl url("https://raw.githubusercontent.com/Sgambe33/WT-Plotter/refs/heads/main/version.json");

#ifdef DEBUG_BUILD
	url = "http://localhost:5000/version";
#endif

	QNetworkRequest request(url);
	QNetworkAccessManager networkManager;
	QNetworkReply* reply = networkManager.get(request);

	QString appVersion = QString("%1.%2.%3")
		.arg(APP_VERSION_MAJOR)
		.arg(APP_VERSION_MINOR)
		.arg(APP_VERSION_PATCH);

	LOG_INFO_GLOBAL(QString("Running wtplotter version %1").arg(appVersion));

	QEventLoop loop;
	QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
	loop.exec();

	if (reply->error() != QNetworkReply::NoError) {
		LOG_WARN_GLOBAL(QString("Failed to fetch version information:%1").arg(reply->errorString()));
		reply->deleteLater();
		return;
	}

	QByteArray responseData = reply->readAll();
	QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
	reply->deleteLater();

	if (!jsonDoc.isObject()) {
		LOG_WARN_GLOBAL("Invalid JSON received.");
		return;
	}

	QJsonObject jsonObj = jsonDoc.object();
	QString latestVersion = jsonObj.value("version").toString();
	QString changelog = jsonObj.value("changelog").toString();
	bool isCritical = jsonObj.value("critical").toBool();

	if (latestVersion.isEmpty()) {
		LOG_WARN_GLOBAL("Version key not found in JSON.");
		return;
	}

	if (appVersion != latestVersion && isCritical) {
		QMessageBox::warning(nullptr, "Update Required", R"(
        <p>A new version of this app has been found. In order to keep shared data consistent, please update by 
        downloading the latest version <a href='https://github.com/Sgambe33/WT-Plotter/releases/latest'>
        here</a>.</p>)" + changelog + R"(<p>Thank you< / p>)");
		std::exit(0);
	}
	else if (appVersion != latestVersion && !isCritical) {
		QMessageBox::information(nullptr, "Update Available", changelog + R"(Update by downloading the latest version <a href='https://github.com/Sgambe33/WT-Plotter/releases/latest'> here</a>)");
		return;
	}
	else {
		return;
	}
}

QFile Utils::getLatestReplay(const QDir& replayDirectory)
{
	QFileInfoList files = replayDirectory.entryInfoList(QDir::Files, QDir::Time);
	if (files.isEmpty())
	{
		return QFile();
	}

	qint64 sixtySecondsAgo = QDateTime::currentMSecsSinceEpoch() - 120000;
	for (const QFileInfo& fileInfo : files)
	{
		if (fileInfo.suffix() == "wrpl" && fileInfo.lastModified().toMSecsSinceEpoch() >= sixtySecondsAgo)
		{
			return QFile(fileInfo.filePath());
		}
	}

	return QFile();
}

void Utils::uploadReplay(Replay& replayData, const QString& uploader, QList<Position> positionCache, QList<Position> poi)
{
	QNetworkAccessManager networkManager;
	QNetworkRequest request(QUrl("https://warthunder-heatmaps.crabdance.com/uploadPositions"));
#ifdef DEBUG_BUILD
	request.setUrl(QUrl("http://localhost:5000/uploadPositions"));
#endif

	request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

	QJsonObject headerMap;
	headerMap["sessionId"] = replayData.getSessionId();
	headerMap["uploader"] = uploader;
	headerMap["startTime"] = replayData.getStartTime();
	headerMap["map"] = replayData.getLevel();
	headerMap["gameMode"] = replayData.getBattleType();
	headerMap["difficulty"] = difficultyToString(replayData.getDifficulty());
	headerMap["wtplotterVersion"] = QString("%1.%2.%3")
		.arg(APP_VERSION_MAJOR)
		.arg(APP_VERSION_MINOR)
		.arg(APP_VERSION_PATCH);

	QJsonObject data;
	data["replayHeader"] = headerMap;
	data["positions"] = exportPositionsToJson(replayData, positionCache, poi);

	QJsonDocument doc(data);
	QByteArray jsonData = doc.toJson();

	QNetworkReply* reply = networkManager.post(request, jsonData);
	QEventLoop loop;
	QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
	loop.exec();

	if (reply->error() != QNetworkReply::NoError)
	{
		LOG_WARN_GLOBAL(QString("Failed to upload replay:%1").arg(reply->errorString()));
	}
	else
	{
		LOG_INFO_GLOBAL("Replay uploaded successfully.");
		LOG_INFO_GLOBAL(QString("Uploaded %1 positions.").arg(data["positions"].toArray().size()));
	}
	reply->deleteLater();
}

QJsonArray Utils::exportPositionsToJson(Replay& replayData, QList<Position> positionCache, QList<Position> poi) {
	QJsonArray positions;
	for (const Position& position : positionCache) {
		QJsonObject obj;
		obj["x"] = position.x();
		obj["y"] = position.y();
		obj["type"] = position.type();
		obj["icon"] = position.icon();
		obj["timestamp"] = position.timestamp();
		obj["sessionId"] = replayData.getSessionId();
		positions.append(obj);
	}
	for (const Position& position : poi) {
		QJsonObject obj;
		obj["x"] = position.x();
		obj["y"] = position.y();
		obj["type"] = position.type();
		obj["icon"] = position.icon();
		obj["timestamp"] = position.timestamp();
		obj["sessionId"] = replayData.getSessionId();
		positions.append(obj);
	}

	return positions;
}

void Utils::saveImage(QPixmap drawedMapImage) {
	QString savePath = QSettings("sgambe33", "wtplotter").value("plotSavePath", "").toString();

	if (drawedMapImage.isNull()) {
		LOG_ERROR_GLOBAL("Error: drawedMapImage is null.");
		return;
	}

	if (savePath.trimmed().isEmpty()) {
		LOG_ERROR_GLOBAL("Error: savePath is not set.");
		QMessageBox msgBox;
		msgBox.critical(nullptr, "Error", "You have not set the save folder in the preferences!");
		return;
	}

	QDir savePathDir(savePath);
	if (!savePathDir.exists()) {
		LOG_ERROR_GLOBAL(QString("Error: savePath directory does not exist: %1").arg(savePath));
		return;
	}

	QString fileName = savePathDir.absoluteFilePath(QString::number(QDateTime::currentSecsSinceEpoch()) + ".jpg");

	QImageWriter writer;
	writer.setFormat("jpg");
	writer.setFileName(fileName);

	if (!writer.write(drawedMapImage.toImage())) {
		LOG_ERROR_GLOBAL(QString("Error saving image: %1").arg(writer.errorString()));
	}
	else {
		LOG_INFO_GLOBAL("Image saved successfully.");
	}
}

QString Utils::replayLengthToString(int length) {
	int hours = length / 3600;
	int minutes = (length % 3600) / 60;
	int seconds = length % 60;
	return QString("%1:%2:%3").arg(hours, 2, 10, QChar('0')).arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0'));
}

QString Utils::difficultyToString(Constants::Difficulty difficulty) {
	switch (difficulty) {
	case Constants::Difficulty::ARCADE:    return "ARCADE";
	case Constants::Difficulty::REALISTIC: return "REALISTIC";
	case Constants::Difficulty::SIMULATOR: return "SIMULATOR";
	default:                    return "UNKNOWN";
	}
}

QString Utils::difficultyToStringLocaleAware(Constants::Difficulty difficulty) {
	switch (difficulty) {
	case Constants::Difficulty::ARCADE:    return QObject::tr("Arcade");
	case Constants::Difficulty::REALISTIC: return QObject::tr("Realistic");
	case Constants::Difficulty::SIMULATOR: return QObject::tr("Simulator");
	default:                    return QObject::tr("UNKNOWN");
	}
}

QString Utils::epochSToFormattedTime(int time) {
	QDateTime startTime = QDateTime::fromSecsSinceEpoch(time);
	return startTime.toString("hh:mm:ss");
}

QIcon Utils::invertIconColors(const QIcon& icon) {
	QPixmap pixmap = icon.pixmap(32, 32);
	QImage image = pixmap.toImage();
	image.invertPixels();
	return QIcon(QPixmap::fromImage(image));
}

QJsonObject Utils::getJsonFromResources(const QString& resourceName, const QString& identifier) {
	QFile file(resourceName);
	if (!file.open(QIODevice::ReadOnly)) {
		LOG_ERROR_GLOBAL(QString("Failed to open file: %1").arg(resourceName));
		return QJsonObject();
	}

	QByteArray data = file.readAll();
	QJsonDocument jsonDoc = QJsonDocument::fromJson(data);

	if (jsonDoc.isNull() || !jsonDoc.isArray()) {
		LOG_ERROR_GLOBAL(QString("Failed to parse JSON array from file: %1").arg(resourceName));
		return QJsonObject();
	}

	QJsonArray jsonArray = jsonDoc.array();

	for (const QJsonValue& value : jsonArray) {
		if (value.isObject()) {
			QJsonObject obj = value.toObject();
			if (obj.contains("identifier") && obj["identifier"].toString() == identifier) {
				return obj;
			}
		}
	}

	LOG_ERROR_GLOBAL(QString("No object found with identifier: %1").arg(identifier));
	return QJsonObject();
}

QString Utils::dhashFromQImage(const QImage& img, int size) {
	QImage gray = img.convertToFormat(QImage::Format_Grayscale8);
	QImage small = gray.scaled(size, size - 1, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

	QVector<int> bits;
	bits.reserve(size * (size - 1));
	for (int y = 0; y < small.height(); ++y) {
		for (int x = 0; x + 1 < small.width(); ++x) {
			int left = QColor(small.pixel(x, y)).value();
			int right = QColor(small.pixel(x + 1, y)).value();
			bits.append(left > right ? 1 : 0);
		}
	}

	QString hexStr;
	for (int i = 0; i < bits.size(); i += 4) {
		int nibble[4] = { 0, 0, 0, 0 };
		for (int j = 0; j < 4 && (i + j) < bits.size(); ++j) {
			nibble[j] = bits[i + j];
		}
		int value = (nibble[0] << 3) | (nibble[1] << 2) | (nibble[2] << 1) | nibble[3];
		hexStr += QString::number(value, 16);
	}

	return hexStr;
}

int Utils::hammingDistanceHex(const QString& h1, const QString& h2) {
	if (h1.length() != h2.length()) {
		return -1;
	}

	int dist = 0;
	for (int i = 0; i < h1.length(); ++i) {
		bool ok1 = false, ok2 = false;
		int v1 = h1.mid(i, 1).toInt(&ok1, 16);
		int v2 = h2.mid(i, 1).toInt(&ok2, 16);
		if (!ok1 || !ok2) {
			LOG_WARN_GLOBAL(QString("Invalid hex digit at position %1").arg(i));
			return -1;
		}
		dist += popcount32(v1 ^ v2);
	}

	return dist;
}

QString Utils::lookupMapName(const QString& hash) {
	for (QString val : Constants::mapHashes.keys()) {
		if (Utils::hammingDistanceHex(hash, val) <= 10)
			return Constants::mapHashes.value(val, {});
	}
	return "unknownmap";
}
#ifndef UTILS_H
#define UTILS_H

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QUrl>
#include <QFile>
#include <QFileInfoList>
#include <QString>
#include <QDebug>
#include <QObject>
#include <QPixmap>
#include <QTimer>
#include <QDir>
#include <QJsonArray>
#include <QList>
#include <QSettings>
#include <QImageWriter>
#include "classes/position.h"
#include "sceneimageviewer.h"
#include "classes/replay.h"
#include "classes/constants.h"
#include <QMap>
#include <QIcon>
#include <QImage>
#include <QFontDatabase>

class Utils {
public:
    static void checkAppVersion();
    static void uploadReplay(Replay& replayData, const QString& uploader, QList<Position> positionCache, QList<Position> poi);
    static QFile getLatestReplay(const QDir& replayDirectory);
    static void saveImage(QPixmap drawedMapImage);
    static QString replayLengthToString(int length);
    static QString difficultyToString(Constants::Difficulty difficulty);
    static QString difficultyToStringLocaleAware(Constants::Difficulty difficulty);
    static QString epochSToFormattedTime(int time);
    static QIcon invertIconColors(const QIcon& icon);
    static QJsonObject getJsonFromResources(const QString& resourceName, const QString& identifier);
    static QString dhashFromQImage(const QImage &img, int size = 16);
    static QString lookupMapName(const QString& hash);


private:
    static int hammingDistanceHex(const QString &h1, const QString &h2);
    static QJsonArray exportPositionsToJson(Replay& replayData, QList<Position> positionCache, QList<Position> poi);
};

#endif // UTILS_H
