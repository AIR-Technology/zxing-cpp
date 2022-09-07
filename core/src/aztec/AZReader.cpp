/*
* Copyright 2016 Nu-book Inc.
* Copyright 2016 ZXing authors
* Copyright 2022 Axel Waggershauser
*/
// SPDX-License-Identifier: Apache-2.0

#include "AZReader.h"

#include "AZDecoder.h"
#include "AZDetector.h"
#include "AZDetectorResult.h"
#include "BinaryBitmap.h"
#include "DecodeHints.h"
#include "DecoderResult.h"
#include "Result.h"

#include <memory>
#include <utility>

namespace ZXing::Aztec {

Result
Reader::decode(const BinaryBitmap& image) const
{
	auto binImg = image.getBitMatrix();
	if (binImg == nullptr)
		return {};

	DetectorResult detectorResult = Detect(*binImg, _hints.isPure(), _hints.tryHarder());
	if (!detectorResult.isValid())
		return {};

	auto decodeResult = Decode(detectorResult).setReaderInit(detectorResult.readerInit()).setIsMirrored(detectorResult.isMirrored());

	return Result(std::move(decodeResult), std::move(detectorResult).position(), BarcodeFormat::Aztec);
}

} // namespace ZXing::Aztec
