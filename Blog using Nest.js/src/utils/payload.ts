import { IsString } from 'class-validator';

export class LinkPayload {
  @IsString()
  name: string;
}
