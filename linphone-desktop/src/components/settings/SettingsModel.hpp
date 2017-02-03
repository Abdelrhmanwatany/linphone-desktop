/*
 * SettingsModel.hpp
 * Copyright (C) 2017  Belledonne Communications, Grenoble, France
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 *  Created on: February 2, 2017
 *      Author: Ronan Abhamon
 */

#ifndef SETTINGS_MODEL_H_
#define SETTINGS_MODEL_H_

#include <linphone++/linphone.hh>
#include <QObject>

// =============================================================================

class SettingsModel : public QObject {
  Q_OBJECT;

  Q_PROPERTY(bool autoAnswerStatus READ getAutoAnswerStatus WRITE setAutoAnswerStatus NOTIFY autoAnswerStatusChanged);
  Q_PROPERTY(QString fileTransferUrl READ getFileTransferUrl WRITE setFileTransferUrl NOTIFY fileTransferUrlChanged);

public:
  SettingsModel (QObject *parent = Q_NULLPTR);

signals:
  void autoAnswerStatusChanged (bool status);
  void fileTransferUrlChanged (const QString &url);

private:
  bool getAutoAnswerStatus () const;
  void setAutoAnswerStatus (bool status);

  QString getFileTransferUrl () const;
  void setFileTransferUrl (const QString &url);

  std::shared_ptr<linphone::Config> m_config;

  static const std::string UI_SECTION;
};

#endif // SETTINGS_MODEL_H_
