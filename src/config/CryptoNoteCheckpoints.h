// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
//
// This file is part of Bytecoin.
//
// Bytecoin is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Bytecoin is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Bytecoin.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <cstddef>
#include <initializer_list>

namespace CryptoNote {
struct CheckpointData {
  uint32_t index;
  const char* blockId;
};

const std::initializer_list<CheckpointData> CHECKPOINTS = { 
{0, "a48d7c8fff886d9e6825e7503dedc07a129f43170542bb74d3df2ee71b0d7ff6"},
{2, "268fea046e05f72c69be3ef55c15687c4fa521b2a2f553534afd54383d685d21"},
{4, "169c558425abc4e89de30d7dbc62edc56598981aec8f7983c3e4f2ada284413a"},
{6, "92870a27b59704d1e49c2b4beb1c91895b55e8a75bbf539a8979588d81e9d49c"},
{8, "1bd4842080cc31dbd0d8eb8cf64c0fd8c95bc8e47a5fd4ef14a5c00919449a85"},
{10, "5eecda13de3f88c97e6cd038be46c0aed7fb3a30b6f1f7a1eb75de2e6d358f56"},
{12, "bd8d0c2f40bdd27166df01607e83cf7e372354cb7e2a5267d4e3ef45d478ef86"},
{14, "9620047cc854540ab9b1898e0f04b79b61bf49ec4ec77fc8bb72f580a8ec1aeb"},
{16, "144e5b49b0618134dc690419fcbde83847536e0515c24084a66da0b7227c95a0"},
{18, "d6dbe62188211785b411db875f1707a8b30114df0c1128b8ab6573d5ba34e51f"},
{20, "d1aae36e0e0a4a9eacbaf3ca552e5ffca34025f53505318cec8102d481fff45d"},
{22, "736c10b9428723b45ae89b766c2df9eee98bc8d06dacf1091695c181721aed92"},
{24, "6b93cc6c77a010182b564d6339928d708002cb7407fe417a49b1786ced9d8cff"},
{26, "4d718ca50649f1c218e7e8d78e02375e2dda83cda61638ff814809e9c3b8c56e"},
{28, "7351d363dd33495eac5339ba262ceffdbf244128b89ac0513b9c204c4585b8da"},
{30, "d76a3887f8bf231282d9eb70ec02dbd764589c20d999314abd19a118d378ddaa"},
{34, "873f81acb411fb6ecc24a94f0314db1638040d5fb8c279ec1c065bf1da5f2f01"},
{38, "f16e40bece25ae8532fe17273134064a9a762a0921c48b532d04acbc6a179db4"},
{44, "b02e4448c40ee85b579dcaf125e247e5360b146885bdc7643f5f3882cc8e1735"},
{46, "0f678ba44a723598f5d275cfd8179024d3f3d8970cf2d103fa7d18483fd72a73"},
{48, "79d17617f48aba75cb507cec6653528bfe927ef4121a03628a20ff9833fb6343"},
{50, "d9201856adb10b431b3ea806ce7d205db3ff2b48e0c7d100a56efb8842411439"},
{60, "b6eb764b3c95aab52fafcdd2b5cbb7470142ecc902955eb234cd062291399536"},
{70, "1071a53f8b7d60882f02ee1346e0426d72b327a2cd4a39deb3830617eccc4a9a"},
{80, "92646d58d67b9808606902862cad977edb6a467eec5fb33afcc81aaba1022d40"},
{90, "a7a3352a030c6f4944699837d26882af63413f7f8d11c5b0ec67f7975effccbb"},
{95, "2783a894b1e8781b4f773a06725929eb47c43ec4a93b70defc2ddece98248d44"},
{97, "54b52fe89ba8afb3a551bfbf509e503c510aedd447de03a7cbe21dbc40cc150b"},
{99, "3cf53716f25ad1da522ad54f8f51f2b93c6198a90cfa093e80982f24882c79b9"},
{100, "1b190d0d83cdc60db5ccda48782ff552a79f21401921b7e25eb7866c62231a32"},
{101, "d364a79b9e58c096479e7475857034907dc0e8458376e0128cc6488f60597951"},
{102, "df5a29c994868c5a1697cf3e6a0e1a4f23d3b3fb9e8a6f086a2e4601938d2373"},
{103, "5f550aaf3651ee7c3b0d05881e25e18958060159f8c2ca7ce08ff5349a52e79a"},
{104, "b807661ef320209e606b9768c29251499cf82a3a4642f4dd56cc16f47b581244"},
{105, "163755205d60cd6967e24a7e87763133f507085741b8b72708ce3c22658975ea"},
{110, "46830958cfd677da7979927bc2ffc44310a16381b45c8b24c80308abba8d7145"},
{115, "930d4c10cf2e792ccc489c7888dd87f82f1ad2f739fab3cfe1c5791ca6d76310"},
{120, "02b2b64aed06c244260a43791f53094542e9085e0559678d3ebb1306aa51b413"},
{130, "29fabf7a93ba844c5c35acb0128cf523458d1d9e11a79390f9a49b7cc3aa1e00"},
{140, "95a05a5c2a19511269cee1708eef7694624bb64305a92541a6e818c675ea9a8d"},
{150, "7228b0053572ac008b208c520aadd6ed5d7720cc319cf7df63cfc722f375dd59"},
{160, "eb7c1356eafff19a27c804d7491e224614f36e0181da58eafa3f87679c6211e9"},
{455, "965fdb7e73a1e14e4e7d2b3349d99883ef1eb72f27d308401eb3f65ce3c249c7"} 
};
}
