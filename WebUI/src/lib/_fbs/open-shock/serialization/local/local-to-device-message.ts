// automatically generated by the FlatBuffers compiler, do not modify

import * as flatbuffers from 'flatbuffers';

import { LocalToDeviceMessagePayload, unionToLocalToDeviceMessagePayload, unionListToLocalToDeviceMessagePayload } from '../../../open-shock/serialization/local/local-to-device-message-payload.js';


export class LocalToDeviceMessage {
  bb: flatbuffers.ByteBuffer|null = null;
  bb_pos = 0;
  __init(i:number, bb:flatbuffers.ByteBuffer):LocalToDeviceMessage {
  this.bb_pos = i;
  this.bb = bb;
  return this;
}

static getRootAsLocalToDeviceMessage(bb:flatbuffers.ByteBuffer, obj?:LocalToDeviceMessage):LocalToDeviceMessage {
  return (obj || new LocalToDeviceMessage()).__init(bb.readInt32(bb.position()) + bb.position(), bb);
}

static getSizePrefixedRootAsLocalToDeviceMessage(bb:flatbuffers.ByteBuffer, obj?:LocalToDeviceMessage):LocalToDeviceMessage {
  bb.setPosition(bb.position() + flatbuffers.SIZE_PREFIX_LENGTH);
  return (obj || new LocalToDeviceMessage()).__init(bb.readInt32(bb.position()) + bb.position(), bb);
}

payloadType():LocalToDeviceMessagePayload {
  const offset = this.bb!.__offset(this.bb_pos, 4);
  return offset ? this.bb!.readUint8(this.bb_pos + offset) : LocalToDeviceMessagePayload.NONE;
}

payload<T extends flatbuffers.Table>(obj:any):any|null {
  const offset = this.bb!.__offset(this.bb_pos, 6);
  return offset ? this.bb!.__union(obj, this.bb_pos + offset) : null;
}

static startLocalToDeviceMessage(builder:flatbuffers.Builder) {
  builder.startObject(2);
}

static addPayloadType(builder:flatbuffers.Builder, payloadType:LocalToDeviceMessagePayload) {
  builder.addFieldInt8(0, payloadType, LocalToDeviceMessagePayload.NONE);
}

static addPayload(builder:flatbuffers.Builder, payloadOffset:flatbuffers.Offset) {
  builder.addFieldOffset(1, payloadOffset, 0);
}

static endLocalToDeviceMessage(builder:flatbuffers.Builder):flatbuffers.Offset {
  const offset = builder.endObject();
  return offset;
}

static finishLocalToDeviceMessageBuffer(builder:flatbuffers.Builder, offset:flatbuffers.Offset) {
  builder.finish(offset);
}

static finishSizePrefixedLocalToDeviceMessageBuffer(builder:flatbuffers.Builder, offset:flatbuffers.Offset) {
  builder.finish(offset, undefined, true);
}

static createLocalToDeviceMessage(builder:flatbuffers.Builder, payloadType:LocalToDeviceMessagePayload, payloadOffset:flatbuffers.Offset):flatbuffers.Offset {
  LocalToDeviceMessage.startLocalToDeviceMessage(builder);
  LocalToDeviceMessage.addPayloadType(builder, payloadType);
  LocalToDeviceMessage.addPayload(builder, payloadOffset);
  return LocalToDeviceMessage.endLocalToDeviceMessage(builder);
}
}
