import { Injectable } from '@nestjs/common';
import { PrismaService } from 'src/prisma/prisma.service';
import { CreatePostDto } from './dto/create-post.dto';
import { UpdatePostDto } from './dto/update-post.dto';

@Injectable()
export class PostsService {
  constructor(private prismaServide: PrismaService) {}
  create(createPostDto: CreatePostDto) {
    const links = createPostDto.name;
    delete createPostDto.name;
    return this.prismaServide.post.create({
      data: {
        ...createPostDto,
        links: {
          create: links,
        },
      },
    });
  }

  findAll(subCategotyId: string) {
    return this.prismaServide.post.findMany({
      where: {
        subCategoryId: subCategotyId,
      },
    });
  }

  findOne(id: string) {
    return this.prismaServide.post.findFirst({
      where: {
        id,
      },
    });
  }

  update(id: string, updatePostDto: UpdatePostDto) {
    return this.prismaServide.post.update({
      data: updatePostDto,
      where: {
        id,
      },
    });
  }

  remove(id: string) {
    return this.prismaServide.post.delete({
      where: {
        id,
      },
    });
  }
}
