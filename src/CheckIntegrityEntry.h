#ifndef __A3_CHECKINTEGRITYENTRY_H__
#define __A3_CHECKINTEGRITYENTRY_H__


#endif /* __A3_CHECKINTEGRITYENTRY_H__ */



#if 0
/*====================================================================*/
/* <!-- copyright */
/*
 * aria2 - The high speed download utility
 *
 * Copyright (C) 2006 Tatsuhiro Tsujikawa
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
#ifndef D_CHECK_INTEGRITY_ENTRY_H
#define D_CHECK_INTEGRITY_ENTRY_H

#include "RequestGroupEntry.h"

#include <vector>
#include <memory>

#include "ProgressAwareEntry.h"

namespace aria2 {

class IteratableValidator;
class DownloadEngine;
class FileAllocationEntry;

class CheckIntegrityEntry : public RequestGroupEntry,
                            public ProgressAwareEntry {
private:
  std::unique_ptr<IteratableValidator> validator_;

protected:
  void setValidator(std::unique_ptr<IteratableValidator> validator);

  void proceedFileAllocation(std::vector<std::unique_ptr<Command>>& commands,
                             std::unique_ptr<FileAllocationEntry> entry,
                             DownloadEngine* e);

public:
  CheckIntegrityEntry(
      RequestGroup* requestGroup,
      std::unique_ptr<Command> nextCommand = std::unique_ptr<Command>());

  virtual ~CheckIntegrityEntry();

  virtual int64_t getTotalLength() CXX11_OVERRIDE;

  virtual int64_t getCurrentLength() CXX11_OVERRIDE;

  virtual void validateChunk();

  virtual bool finished() CXX11_OVERRIDE;

  virtual bool isValidationReady() = 0;

  virtual void initValidator() = 0;

  virtual void
  onDownloadFinished(std::vector<std::unique_ptr<Command>>& commands,
                     DownloadEngine* e) = 0;

  virtual void
  onDownloadIncomplete(std::vector<std::unique_ptr<Command>>& commands,
                       DownloadEngine* e) = 0;

  void cutTrailingGarbage();
};

} // namespace aria2

#endif // D_CHECK_INTEGRITY_ENTRY_H
/*====================================================================*/
#endif

