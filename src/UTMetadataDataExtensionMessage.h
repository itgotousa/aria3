#ifndef __A3_UTMETADATADATAEXTENSIONMESSAGE_H__
#define __A3_UTMETADATADATAEXTENSIONMESSAGE_H__


#endif /* __A3_UTMETADATADATAEXTENSIONMESSAGE_H__ */



#if 0
/*====================================================================*/
/* <!-- copyright */
/*
 * aria2 - The high speed download utility
 *
 * Copyright (C) 2009 Tatsuhiro Tsujikawa
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *
 * In addition, as a special exception, the copyright holders give
 * permission to link the code of portions of this program with the
 * OpenSSL library under certain conditions as described in each
 * individual source file, and distribute linked combinations
 * including the two.
 * You must obey the GNU General Public License in all respects
 * for all of the code used other than OpenSSL.  If you modify
 * file(s) with this exception, you may extend this exception to your
 * version of the file(s), but you are not obligated to do so.  If you
 * do not wish to do so, delete this exception statement from your
 * version.  If you delete this exception statement from all source
 * files in the program, then also delete it here.
 */
/* copyright --> */
#ifndef D_UT_METADATA_DATA_EXTENSION_MESSAGE_H
#define D_UT_METADATA_DATA_EXTENSION_MESSAGE_H

#include "UTMetadataExtensionMessage.h"

#include <memory>

namespace aria2 {

class DownloadContext;
class PieceStorage;
class UTMetadataRequestTracker;

class UTMetadataDataExtensionMessage : public UTMetadataExtensionMessage {
private:
  size_t totalSize_;

  std::string data_;

  DownloadContext* dctx_;

  PieceStorage* pieceStorage_;

  UTMetadataRequestTracker* tracker_;

public:
  UTMetadataDataExtensionMessage(uint8_t extensionMessageID);

  virtual std::string getPayload() CXX11_OVERRIDE;

  virtual std::string toString() const CXX11_OVERRIDE;

  virtual void doReceivedAction() CXX11_OVERRIDE;

  void setTotalSize(size_t totalSize);

  size_t getTotalSize() const;

  void setData(const std::string& data);

  template <typename InputIterator>
  void setData(InputIterator first, InputIterator last)
  {
    data_.assign(first, last);
  }

  const std::string& getData() const;

  void setPieceStorage(PieceStorage* pieceStorage);

  void setUTMetadataRequestTracker(UTMetadataRequestTracker* tracker);

  void setDownloadContext(DownloadContext* dctx);
};

} // namespace aria2

#endif // D_UT_METADATA_DATA_EXTENSION_MESSAGE_H
/*====================================================================*/
#endif

